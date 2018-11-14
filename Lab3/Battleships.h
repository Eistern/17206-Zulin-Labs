#ifndef LAB3_BATTLESHIPS_H
#define LAB3_BATTLESHIPS_H

#include <vector>
#include "Gamer.h"
#include "GameView.h"
#include "Board.h"

class Battleships {
public:
    void run(const Gamer &player1, const Gamer &player2, int count = 1) const;
private:
    void placeStage(const Gamer&, Board&, const GameView &screen) const;
    void hitStage(const Gamer&, Board&, const GameView &screen) const;
};


#endif //LAB3_BATTLESHIPS_H
