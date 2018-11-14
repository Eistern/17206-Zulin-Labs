#include <iostream>
#include <fstream>
#include "Battleships.h"
#include "ViewTypes/ConsoleView.h"
#include "GamerTypes/ConsoleGamer.h"
#include "GamerTypes/RandomGamer.h"

//TODO parse arguments of main, write helping list, implement creators for different types of players

int main(int argc, char* argv[]) {
    std::ofstream out("log.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    Gamer* _player1 = new RandomGamer;
    Gamer* _player2 = new RandomGamer;
    Battleships _game;
    _game.run(*_player1, *_player2);

    std::cout.rdbuf(coutbuf);
    return 0;
}