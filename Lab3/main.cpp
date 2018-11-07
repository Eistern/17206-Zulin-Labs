#include <iostream>
#include "Battleships.h"
#include "ViewTypes/ConsoleView.h"
#include "GamerTypes/ConsoleGamer.h"
#include "GamerTypes/RandomGamer.h"

//TODO parse arguments of main, write helping list, implement creators for different types of players

int main(int argc, char* argv[]) {
    GameView* _screen = new ConsoleView;
    Gamer* _player1 = new RandomGamer;
    Gamer* _player2 = new RandomGamer;
    Battleships _game;
    _game.run(*_player1, *_player2, *_screen);
    return 0;
}