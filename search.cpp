#include <climits>

#include "grid.hpp"

struct Move {
    int* position;
    int score;
};

Move minmax(TicTacToeGrid grid, int depth, bool player) {
    if (depth == 0 || grid.is_endgame()) {
        return Move{new int[2]{}, 0};
    }

    if (player) {
        Move move = Move{new int[2]{}, INT_MIN};
        std::vector<int*> moves = grid.getMoves();
        for (auto it = moves.begin(); it != moves.end(); it++) {
            int* pos = *it;
        }

    } else {
    }
}

