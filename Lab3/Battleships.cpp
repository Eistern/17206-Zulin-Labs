#include "Battleships.h"
#include "ViewTypes/ConsoleView.h"

void Battleships::run(Gamer &player1, Gamer &player2, int count) const {
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
            while (!secondBoard.isWin() && hitStage(player1, secondBoard, *screen))
                screen->sendMessage("Hit correct!\n");

            screen->sendMessage("Second player turn\n");
            while (!firstBoard.isWin() && hitStage(player2, firstBoard, *screen))
                screen->sendMessage("Hit correct!\n");
        }

        if (firstBoard.isWin())
            screen->sendMessage("Second player wins!");
        else
            screen->sendMessage("First player wins!");
    }
}

void Battleships::placeStage(Gamer &player, Board &playerBoard, const GameView &screen) const {
    std::vector<unsigned int> currentChoice;
    screen.sendMessage("Input coordinates and direction(H/W) of your ships\n");

    for (int length = 1; length < 5; ++length)
        for (int j = 0; j < 5 - length; ++j) {
            screen.printBoard(playerBoard);
            currentChoice = player.setShip();

            while (!playerBoard.validateSet(currentChoice, length)) {
                screen.sendMessage("Invalid placement, please try again\n");
                currentChoice = player.setShip();
            }

            playerBoard.setShip(currentChoice, length);
        }

    screen.printBoard(playerBoard);
}

bool Battleships::hitStage(Gamer &player, Board &opponentBoard, const GameView &screen) const {
    std::vector<unsigned int> currentChoice;

    screen.printBoard(opponentBoard);
    currentChoice = player.hitShip(opponentBoard);

    while (!opponentBoard.validateHit(currentChoice)) {
        screen.sendMessage("Invalid hit(already hit this place), please try again\n");
        currentChoice = player.hitShip(opponentBoard);
    }

    bool result = opponentBoard.hitShip(currentChoice);
    return result;
}