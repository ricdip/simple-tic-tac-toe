#include "game/game.hpp"

int main(void) {
    TicTacToeGame game;
    int maxDepth = 9;

    // Tic Tac Toe AI vs AI mode
    game.AIvsAI(maxDepth);
    // Tic Tac Toe Player vs AI mode
    // game.PlayervsAI(maxDepth);

    return 0;
}
