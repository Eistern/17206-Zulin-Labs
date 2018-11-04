#ifndef LAB3_BATTLESHIPS_H
#define LAB3_BATTLESHIPS_H

#include <utility>
#include "Gamer.h"
#include "GameView.h"

class Battleships {
public:
    void run(const Gamer &player1, const Gamer &player2, const GameView& screen, int count = 1) const;
    class Board {
        friend class Battleships;
        Board() = default;
        int _board[10][10] = {0};
    public:
        void printBoard(bool printAll, const GameView& screen) const;
        void setShip(std::pair<unsigned int, unsigned int>, char rotation, int size);
        bool hitShip(std::pair<unsigned int, unsigned int>);
        bool validateSet(std::pair<unsigned int, unsigned int>, char rotation, int size) const;
        bool validateHit(std::pair<unsigned int, unsigned int>) const;
    };
private:
    void initBoard(const Gamer &player, const Board &board, const GameView &screen) const;
};


#endif //LAB3_BATTLESHIPS_H
