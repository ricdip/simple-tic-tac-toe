#include "heuristics.hpp"

#include <climits>

int H(TicTacToeGrid grid) {
    char winner = grid.victory_player();
    if (winner == P1) {
        return INT_MAX;
    } else if (winner == P2) {
        return INT_MIN;
    } else {
        return 0;
    }
}
