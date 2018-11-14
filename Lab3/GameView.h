#ifndef LAB3_GAMEVIEW_H
#define LAB3_GAMEVIEW_H

#include <string>
#include "Battleships.h"

class GameView {
public:
    virtual void sendMessage(const std::string &message) const = 0;
    virtual void printBoard() const = 0;
    virtual ~GameView() = default;
};

#endif //LAB3_GAMEVIEW_H
