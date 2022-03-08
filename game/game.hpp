#ifndef GAME_HPP
#define GAME_HPP

#include "move.hpp"

class TicTacToeGame {
   public:
    Move getPlayerMove();

    void AIvsAI(int maxDepth);

    void PlayervsAI(int maxDepth);
};

#endif
