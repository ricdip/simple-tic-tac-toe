#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "move.hpp"
#include "state.hpp"

class Algorithm {
   private:
    int maxDepth;
    Move bestMove;

    int minmaxAux(TicTacToeState state, int depth, bool player);

   public:
    Algorithm(int d);
    Move minmax(TicTacToeState state, bool player);
};

#endif
