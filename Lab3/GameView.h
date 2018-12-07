#ifndef LAB3_GAMEVIEW_H
#define LAB3_GAMEVIEW_H

#include <string>
#include "Board.h"

class GameView {
public:
    virtual void sendMessage(const std::string &) const = 0;
    virtual void printBoard(const Board&) const = 0;
    virtual ~GameView() = default;
};

#endif //LAB3_GAMEVIEW_H
