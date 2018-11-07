#ifndef LAB3_BATTLESHIPS_H
#define LAB3_BATTLESHIPS_H

#include <vector>
#include "Gamer.h"
#include "GameView.h"

class Battleships {
public:
    void run(const Gamer &player1, const Gamer &player2, const GameView& screen, int count = 1) const;
    class Board {
        friend class Battleships;
        Board() = default;
        int _board[10][10] = {{0}};
    public:
        void printBoard(bool printAll, const GameView& screen) const;
        void setShip(std::vector<unsigned int>, int size);
        bool hitShip(std::vector<unsigned int>);
        bool validateSet(std::vector<unsigned int>, int size) const;
        bool validateHit(std::vector<unsigned int>) const;
        bool isWin() const;
    };
private:
    void placeStage(const Gamer&, Board&, const GameView &screen) const;
    void hitStage(const Gamer&, Board&, Board&, const GameView &screen) const;
};


#endif //LAB3_BATTLESHIPS_H
