#include "algorithms.hpp"

#include <climits>

#include "heuristics.hpp"

int Algorithm::minmaxAux(TicTacToeState state, int depth, bool player) {
    if (depth == 0 || state.isEndgame()) {
        return H(state);
    }

    if (player) {
        int bestValue = INT_MIN;
        std::vector<Move> moves = state.getMoves();
        for (auto it = moves.begin(); it != moves.end(); it++) {
            TicTacToeState g = state.makeMove(player, *it);

            int value = minmaxAux(g, depth - 1, false);
            if (bestValue < value) {
                bestValue = value;
                if (depth == maxDepth) {
                    bestMove = *it;
                }
            }
        }
        return bestValue;

    } else {
        int bestValue = INT_MAX;
        std::vector<Move> moves = state.getMoves();
        for (auto it = moves.begin(); it != moves.end(); it++) {
            TicTacToeState g = state.makeMove(player, *it);

            int value = minmaxAux(g, depth - 1, true);
            if (bestValue > value) {
                bestValue = value;
                if (depth == maxDepth) {
                    bestMove = *it;
                }
            }
        }
        return bestValue;
    }
}

Algorithm::Algorithm(int d) {
    maxDepth = d;
    bestMove = Move();
}

Move Algorithm::minmax(TicTacToeState state, bool player) {
    bestMove = Move();

    minmaxAux(state, maxDepth, player);

    return bestMove;
}
