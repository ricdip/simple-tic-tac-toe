#include "algorithms.hpp"

#include <climits>

#include "../heuristics/heuristics.hpp"

Algorithm::Algorithm(int d) {
    maxDepth = d;
    bestMove = Move();
}

// MinMax algorithm
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

Move Algorithm::minmax(TicTacToeState state, bool player) {
    bestMove = Move();

    minmaxAux(state, maxDepth, player);

    return bestMove;
}

// MinMax Alpha-Beta algorithm (fail-hard version)
int Algorithm::minmaxAlphaBetaAux(TicTacToeState state, int depth, int alpha,
                                  int beta, bool player) {
    if (depth == 0 || state.isEndgame()) {
        return H(state);
    }

    if (player) {
        int bestValue = INT_MIN;
        std::vector<Move> moves = state.getMoves();
        for (auto it = moves.begin(); it != moves.end(); it++) {
            TicTacToeState g = state.makeMove(player, *it);

            int value = minmaxAlphaBetaAux(g, depth - 1, alpha, beta, false);
            if (bestValue < value) {
                bestValue = value;
                if (depth == maxDepth) {
                    bestMove = *it;
                }
            }

            // cutoff check
            if (value >= beta) {
                // beta cutoff
                break;
            }
            alpha = std::max(alpha, value);
        }
        return bestValue;

    } else {
        int bestValue = INT_MAX;
        std::vector<Move> moves = state.getMoves();
        for (auto it = moves.begin(); it != moves.end(); it++) {
            TicTacToeState g = state.makeMove(player, *it);

            int value = minmaxAlphaBetaAux(g, depth - 1, alpha, beta, true);
            if (bestValue > value) {
                bestValue = value;
                if (depth == maxDepth) {
                    bestMove = *it;
                }
            }

            // cutoff check
            if (value <= alpha) {
                // alpha cutoff
                break;
            }
            beta = std::min(beta, value);
        }
        return bestValue;
    }
}

Move Algorithm::minmaxAlphaBeta(TicTacToeState state, bool player) {
    bestMove = Move();

    minmaxAlphaBetaAux(state, maxDepth, INT_MIN, INT_MAX, player);

    return bestMove;
}
