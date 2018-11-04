#ifndef LAB3_CONSOLEVIEW_H
#define LAB3_CONSOLEVIEW_H

#include "../GameView.h"

class ConsoleView : public GameView {
public:
    void sendMessage(const std::string &message) override;
    void updateBoard(const Battleships::Board &playerBoard, const Battleships::Board &opponentBoard) override;
};


#endif //LAB3_CONSOLEVIEW_H
