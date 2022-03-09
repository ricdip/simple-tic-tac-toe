#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "../game/move.hpp"
#include "../game/state.hpp"

#define MINMAX "minmax"
#define MINMAX_ALPHA_BETA "minmax_alpha_beta"

class Algorithm {
   private:
    int maxDepth;
    Move bestMove;

    int minmaxAux(TicTacToeState state, int depth, bool player);
    int minmaxAlphaBetaAux(TicTacToeState state, int depth, int alpha, int beta,
                           bool player);

   public:
    Algorithm(int d);
    Move minmax(TicTacToeState state, bool player);
    Move minmaxAlphaBeta(TicTacToeState state, bool player);
};

#endif
