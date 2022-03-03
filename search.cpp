#include "search.hpp"

#include <climits>

const Move& max(const Move& m1, const Move& m2) {
    if (m1.getScore() >= m2.getScore()) {
        return m1;
    } else {
        return m2;
    }
}

const Move& min(const Move& m1, const Move& m2) {
    if (m1.getScore() <= m2.getScore()) {
        return m1;
    } else {
        return m2;
    }
}

Move minmax(TicTacToeGrid grid, int depth, bool player) {
    if (depth == 0 || grid.is_endgame()) {
        return Move(new int[2]{}, H(grid));
    }

    if (player) {
        Move bestMove = Move{new int[2]{}, INT_MIN};
        std::vector<int*> moves = grid.getMoves();
        for (auto it = moves.begin(); it != moves.end(); it++) {
            TicTacToeGrid g = grid.makeMove(player, *it);
            bestMove = max(bestMove, minmax(g, depth - 1, false));
        }
        return bestMove;

    } else {
        Move bestMove = Move(new int[2]{}, INT_MAX);
        std::vector<int*> moves = grid.getMoves();
        for (auto it = moves.begin(); it != moves.end(); it++) {
            TicTacToeGrid g = grid.makeMove(player, *it);
            bestMove = min(bestMove, minmax(g, depth - 1, true));
        }
        return bestMove;
    }
}

