#include "heuristics.hpp"

#include <climits>

int H(TicTacToeState state) {
    char winner = state.victoryPlayer();
    if (winner == P1) {
        return INT_MAX;
    } else if (winner == P2) {
        return INT_MIN;
    } else {
        return 0;
    }
}
