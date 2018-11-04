#include <iostream>
#include "externalLib/optionparser.h"
#include <vector>
#include <string>

enum optionIndex { HELP, };
const option::Descriptor usage[] = {
        {HELP, 0, "h", "help", option::Arg::None, "xui"},
        {0, 0, 0, 0, 0, 0}
};

int main(int argc, char* argv[]) {
    argc-=(argc>0); argv+=(argc>0); // skip program name argv[0] if present
    option::Stats  stats(usage, argc, argv);
    std::vector<option::Option> options(stats.options_max);
    std::vector<option::Option> buffer(stats.buffer_max);
    option::Parser parse(usage, argc, argv, &options[0], &buffer[0]);

    if (parse.error())
        return 1;

    if (options[HELP] || argc == 0) {
        option::printUsage(std::cout, usage);
        return 0;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}