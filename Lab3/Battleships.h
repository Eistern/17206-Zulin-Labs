#ifndef LAB3_BATTLESHIPS_H
#define LAB3_BATTLESHIPS_H

#include <vector>
#include "Gamer.h"
#include "GameView.h"
#include "Board.h"

class Battleships {
public:
    void run(Gamer &, Gamer &, int) const;
private:
    void placeStage(Gamer&, Board&, const GameView &) const;
    bool hitStage(Gamer&, Board&, const GameView &) const;
};


#endif //LAB3_BATTLESHIPS_H
