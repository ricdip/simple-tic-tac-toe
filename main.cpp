#include <iostream>

#include "grid.hpp"

int main(void) {
    TicTacToeGrid grid;
    grid.print();

    std::cout << std::endl;

    std::vector<int*> moves = grid.getMoves();

    for (auto it = moves.begin(); it != moves.end(); it++) {
        int* pos = *it;
        std::cout << pos[0] << "," << pos[1] << std::endl;
    }

    return 0;
}
