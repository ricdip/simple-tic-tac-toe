#include "grid.hpp"

#include <iostream>

TicTacToeGrid::TicTacToeGrid() {}
TicTacToeGrid::TicTacToeGrid(char g[ROWS][COLS], bool t) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = g[i][j];
        }
    }
    turn = t;
}

void TicTacToeGrid::print() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool TicTacToeGrid::getTurn() { return turn; }

TicTacToeGrid& TicTacToeGrid::makeMove(bool player, int position[2]) {
    TicTacToeGrid* newGrid = new TicTacToeGrid(grid, !player);
    if (player) {
        newGrid->grid[position[0]][position[1]] = P1;
    } else {
        newGrid->grid[position[0]][position[1]] = P2;
    }

    newGrid->lastMove->setPosition(position);

    return *newGrid;
}

std::vector<int*> TicTacToeGrid::getMoves() {
    std::vector<int*> positions = std::vector<int*>();

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == OO) {
                positions.push_back(new int[2]{i, j});
            }
        }
    }

    return positions;
}

bool TicTacToeGrid::is_endgame() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == OO) {
                return false;
            }
        }
    }
    return true;
}

char TicTacToeGrid::victory_player() {
    // horizontal
    if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][2] != OO

    ) {
        return grid[0][0];
    }

    if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] && grid[1][2] != OO

    ) {
        return grid[1][0];
    }

    if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][2] != OO

    ) {
        return grid[2][0];
    }

    // vertical
    if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[2][0] != OO

    ) {
        return grid[0][0];
    }

    if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[2][1] != OO

    ) {
        return grid[0][1];
    }

    if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[2][2] != OO

    ) {
        return grid[0][2];
    }

    // diagonal
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] != OO

    ) {
        return grid[0][0];
    }

    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] != OO

    ) {
        return grid[0][2];
    }

    return OO;
}

Move TicTacToeGrid::getLastMove() { return *lastMove; }
