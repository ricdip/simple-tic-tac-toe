#include "state.hpp"

#include <iostream>

TicTacToeState::TicTacToeState() {}
TicTacToeState::TicTacToeState(char g[ROWS][COLS], bool t) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = g[i][j];
        }
    }
    turn = t;
}

void TicTacToeState::print() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool TicTacToeState::getTurn() { return turn; }

TicTacToeState TicTacToeState::makeMove(bool player, Move move) {
    TicTacToeState newGrid = TicTacToeState(grid, !player);

    if (player) {
        newGrid.grid[move.getPosition()[0]][move.getPosition()[1]] = P1;
    } else {
        newGrid.grid[move.getPosition()[0]][move.getPosition()[1]] = P2;
    }

    return newGrid;
}

std::vector<Move> TicTacToeState::getMoves() {
    std::vector<Move> moves = std::vector<Move>();

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == OO) {
                int pos[] = {i, j};
                moves.push_back(Move(pos));
            }
        }
    }

    return moves;
}

bool TicTacToeState::isEndgame() {
    if (victoryPlayer() != OO) {
        return true;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == OO) {
                return false;
            }
        }
    }
    return true;
}

char TicTacToeState::victoryPlayer() {
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
