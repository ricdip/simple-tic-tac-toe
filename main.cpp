#include <iostream>

#include "search.hpp"

int main(void) {
    TicTacToeGrid grid;

    while (!grid.is_endgame()) {
        // return 0;
        bool turn = grid.getTurn();
        Move m = minmax(grid, 9, turn);
        int* pos = m.getPosition();

        grid = grid.makeMove(turn, pos);

        grid.print();
        std::cout << "pos: " << pos[0] << "," << pos[1] << std::endl;
        std::cout << "score: " << m.getScore() << std::endl;
        std::cout << "endgame: " << grid.is_endgame() << std::endl;
        std::cout << "victory_player: " << grid.victory_player() << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
