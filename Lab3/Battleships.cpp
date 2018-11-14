#include "Battleships.h"
#include "ViewTypes/ConsoleView.h"

void Battleships::run(const Gamer &player1, const Gamer &player2, int count) const {
    GameView* screen = new ConsoleView;
    for (int i = 0; i < count; ++i) {
        Board firstBoard;
        Board secondBoard;
        screen->sendMessage("New round\n");
        screen->sendMessage("First player placing ships\n");
        placeStage(player1, firstBoard, *screen);
        screen->sendMessage("Second player placing ships\n");
        placeStage(player2, secondBoard, *screen);
        firstBoard.gameStarted = true;
        secondBoard.gameStarted = true;
        while (!firstBoard.isWin() && !secondBoard.isWin()) {
            screen->sendMessage("First player turn\n");
            hitStage(player1, secondBoard, *screen);
            screen->sendMessage("Second player turn\n");
            hitStage(player2, firstBoard, *screen);
        }
        if (firstBoard.isWin())
            screen->sendMessage("Second player wins!");
        else
            screen->sendMessage("First player wins!");
    }
}

void Battleships::placeStage(const Gamer &player, Board &playerBoard, const GameView &screen) const {
    std::vector<unsigned int> currentChoice;
    screen.sendMessage("Input coordinates and direction(H/W) of your ships\n");
    for (int length = 1; length < 5; ++length)
        for (int j = 0; j < 5 - length; ++j) {
//            playerBoard.printBoard(true, screen);
            screen.printBoard(playerBoard);
            currentChoice = player.setShip();
            while (!playerBoard.validateSet(currentChoice, length)) {
                screen.sendMessage("Invalid placement, please try again\n");
                currentChoice = player.setShip();
            }
            playerBoard.setShip(currentChoice, length);
        }
//    playerBoard.printBoard(true, screen);
    screen.printBoard(playerBoard);
}

void Battleships::hitStage(const Gamer &player, Board &opponentBoard, const GameView &screen) const {
    std::vector<unsigned int> currentChoice;
//    playerBoard.printBoard(true, screen);
//    opponentBoard.printBoard(false, screen);
    screen.printBoard(opponentBoard);
    currentChoice = player.hitShip();
    while (!opponentBoard.validateHit(currentChoice)) {
        screen.sendMessage("Invalid hit(already hit this place), please try again\n");
        currentChoice = player.hitShip();
    }
    bool result = opponentBoard.hitShip(currentChoice);
}