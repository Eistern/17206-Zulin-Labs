#include <iostream>
#include <fstream>
#include <cstring>
#include "Battleships.h"
#include "ViewTypes/ConsoleView.h"
#include "GamerTypes/GamerFactory.h"
#include "externalLib/optionparser.h"

static void printError(const char *msg1, const option::Option &opt, const char *msg2) {
    fprintf(stderr, "ERROR: %s", msg1);
    fwrite(opt.name, opt.namelen, 1, stderr);
    fprintf(stderr, "%s", msg2);
}

static option::ArgStatus PlayerType(const option::Option &option, bool msg) {
    if (option.arg != nullptr && (strcmp(option.arg, "=random") == 0 || strcmp(option.arg, "=console") == 0 ||
                                  strcmp(option.arg, "=optimal") == 0))
        return option::ARG_OK;

    if (msg)
        printError("Option '", option, "' requires random/console/optimal type of player\n");
    return option::ARG_ILLEGAL;
}

static option::ArgStatus Numeric(const option::Option &option, bool msg) {
    char *endptr = nullptr;
    if (option.arg != nullptr && strtol(option.arg, &endptr, 10)) {};
    if (endptr != option.arg && *endptr == 0)
        return option::ARG_OK;

    if (msg)
        printError("Option '", option, "' requires a numeric argument\n");
    return option::ARG_ILLEGAL;
}

enum optionIndex {
    ROUNDS, PLAYER, HELP
};
enum optionType {
    FIRST, SECOND
};

const option::Descriptor usage[] = {
        {ROUNDS, 0,      "c", "count",  Numeric,           "-c, --count \t|Defines number of rounds \t|Default: 1"},
        {PLAYER, FIRST,  "f", "first",  PlayerType,        "-f, --first \t|Defines type of first player \t|Default: random"},
        {PLAYER, SECOND, "s", "second", PlayerType,        "-s, --second \t|Defines type of second player \t|Default: random"},
        {HELP,   0,      "h", "help",   option::Arg::None, "-h, --help \t|Prints out usage of options"}
};

int main(int argc, char *argv[]) {
    argc -= (argc > 0);
    argv += (argc > 0); // skip program name argv[0] if present
    option::Stats stats(usage, argc, argv);
    option::Option options[stats.options_max], buffer[stats.buffer_max];
    option::Parser parse(usage, argc, argv, options, buffer);

    if (parse.error())
        return 1;
    if (options[HELP] || argc == 0) {
        option::printUsage(std::cout, usage);
        return 0;
    }

    Gamer *_player1 = nullptr;
    Gamer *_player2 = nullptr;
    int count = 1;

    if (options[ROUNDS])
        count = atoi(options[ROUNDS].last()->arg);
    for (option::Option *opt = options[PLAYER]; opt; opt = opt->next()) {
        switch (opt->type()) {
            case FIRST :
                if (_player1 == nullptr)
                    _player1 = factoryMethod(opt->arg);
                break;
            case SECOND:
                if (_player2 == nullptr)
                    _player2 = factoryMethod(opt->arg);
                break;
            default:
                return 2;
        }
    }
    if (_player1 == nullptr)
        _player1 = new RandomGamer;
    if (_player2 == nullptr)
        _player2 = new RandomGamer;

    std::ofstream out("log.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to log.txt!


    Battleships _game;
    _game.run(*_player1, *_player2, count);

    std::cout.rdbuf(coutbuf);
    return 0;
}