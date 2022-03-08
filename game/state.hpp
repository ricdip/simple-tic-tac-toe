#ifndef STATE_HPP
#define STATE_HPP

#include <vector>

#include "move.hpp"

#define ROWS 3
#define COLS 3

#define OO '.'
#define P1 'X'
#define P2 'O'

class TicTacToeState {
   private:
    // clang-format off
    char grid[ROWS][COLS] = {
        OO, OO, OO,
        OO, OO, OO,
        OO, OO, OO,
    };

    bool turn = true;
    // clang-format on

   public:
    TicTacToeState();
    TicTacToeState(char g[ROWS][COLS], bool t);
    void print();
    bool getTurn();
    TicTacToeState makeMove(bool player, Move move);
    std::vector<Move> getMoves();
    bool isEndgame();
    char victoryPlayer();
};

#endif
