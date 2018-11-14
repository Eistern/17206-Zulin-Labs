#ifndef LAB3_BATTLESHIPS_H
#define LAB3_BATTLESHIPS_H

#include <vector>
#include "Gamer.h"
#include "GameView.h"

class Battleships {
public:
    void run(const Gamer &player1, const Gamer &player2, int count = 1) const;
    class Board {
        bool gameStarted = false;
        friend class Battleships;
        Board() = default;
        int _board[10][10] = {{0}};
    public:
        void setShip(std::vector<unsigned int>, int size);
        bool hitShip(std::vector<unsigned int>);
        bool validateSet(std::vector<unsigned int>, int size) const;
        bool validateHit(std::vector<unsigned int>) const;
        bool isWin() const;
    };
private:
    void placeStage(const Gamer&, Board&, const GameView &screen) const;
    void hitStage(const Gamer&, Board&, const GameView &screen) const;
};


#endif //LAB3_BATTLESHIPS_H
