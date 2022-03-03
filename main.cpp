#include <iostream>

#include "search.hpp"

int main(void) {
    TicTacToeGrid grid;
    grid.print();

    Move m = minmax(grid, 9, true);

    int* pos = m.getPosition();
    std::cout << pos[0] << "," << pos[1] << std::endl;
    std::cout << m.getScore() << std::endl;

    return 0;
}
