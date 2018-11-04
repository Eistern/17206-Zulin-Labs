#ifndef LAB3_GAMEVIEW_H
#define LAB3_GAMEVIEW_H

#include <string>
#include "Battleships.h"

class GameView {
public:
    virtual void sendMessage(const std::string &message) = 0;
    virtual void updateBoard(const Battleships::Board &playerBoard, const Battleships::Board &opponentBoard) = 0;
    virtual ~GameView() = default;
};

#endif //LAB3_GAMEVIEW_H
