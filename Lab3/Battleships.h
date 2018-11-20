#ifndef LAB3_BATTLESHIPS_H
#define LAB3_BATTLESHIPS_H

#include <vector>
#include "Gamer.h"
#include "GameView.h"
#include "Board.h"

class Battleships {
public:
    void run(Gamer &player1, Gamer &player2, int count) const;
private:
    void placeStage(Gamer&, Board&, const GameView &screen) const;
    bool hitStage(Gamer&, Board&, const GameView &screen) const;
};


#endif //LAB3_BATTLESHIPS_H
