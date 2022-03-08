#include <climits>
#include <iostream>
#include <vector>

#define ROWS 3
#define COLS 3

#define OO '.'
#define P1 'X'
#define P2 'O'

class Move {
   private:
    int position[2];
    int score;

   public:
    Move(){};
    Move(int pos[2]);
    Move(int pos[2], int s);
    int* getPosition();
    void setPosition(int pos[2]);
    int getScore();
    void setScore(int s);
};

Move::Move(int pos[2]) { setPosition(pos); }

Move::Move(int pos[2], int s) {
    setPosition(pos);
    score = s;
}

int* Move::getPosition() { return position; }

void Move::setPosition(int pos[2]) {
    position[0] = pos[0];
    position[1] = pos[1];
}

int Move::getScore() { return score; }

void Move::setScore(int s) { score = s; }

class TicTacToeGrid {
   private:
    // clang-format off
    char grid[ROWS][COLS] = {
        OO, OO, OO,
        OO, OO, OO,
        OO, OO, OO,
    };

    bool turn = true;
    // clang-format on

   public:
    TicTacToeGrid();
    TicTacToeGrid(char g[ROWS][COLS], bool t);
    void print();
    bool getTurn();
    TicTacToeGrid makeMove(bool player, Move move);
    std::vector<Move> getMoves();
    bool isEndgame();
    char victoryPlayer();
};

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

TicTacToeGrid TicTacToeGrid::makeMove(bool player, Move move) {
    TicTacToeGrid newGrid = TicTacToeGrid(grid, !player);

    if (player) {
        newGrid.grid[move.getPosition()[0]][move.getPosition()[1]] = P1;
    } else {
        newGrid.grid[move.getPosition()[0]][move.getPosition()[1]] = P2;
    }

    return newGrid;
}

std::vector<Move> TicTacToeGrid::getMoves() {
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

bool TicTacToeGrid::isEndgame() {
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

char TicTacToeGrid::victoryPlayer() {
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

int H(TicTacToeGrid grid) {
    char winner = grid.victoryPlayer();
    if (winner == P1) {
        return INT_MAX;
    } else if (winner == P2) {
        return INT_MIN;
    } else {
        return 0;
    }
}

class Algorithm {
   private:
    int maxDepth;
    Move bestMove;

    int minmaxAux(TicTacToeGrid grid, int depth, bool player) {
        if (depth == 0 || grid.isEndgame()) {
            return H(grid);
        }

        if (player) {
            int bestValue = INT_MIN;
            std::vector<Move> moves = grid.getMoves();
            for (auto it = moves.begin(); it != moves.end(); it++) {
                TicTacToeGrid g = grid.makeMove(player, *it);

                int value = minmaxAux(g, depth - 1, false);
                if (bestValue < value) {
                    bestValue = value;
                    if (depth == maxDepth) {
                        bestMove = *it;
                    }
                }
            }
            return bestValue;

        } else {
            int bestValue = INT_MAX;
            std::vector<Move> moves = grid.getMoves();
            for (auto it = moves.begin(); it != moves.end(); it++) {
                TicTacToeGrid g = grid.makeMove(player, *it);

                int value = minmaxAux(g, depth - 1, true);
                if (bestValue > value) {
                    bestValue = value;
                    if (depth == maxDepth) {
                        bestMove = *it;
                    }
                }
            }
            return bestValue;
        }
    }

   public:
    Algorithm(int d) {
        maxDepth = d;
        bestMove = Move();
    }
    Move minmax(TicTacToeGrid grid, bool player) {
        bestMove = Move();

        minmaxAux(grid, maxDepth, player);

        return bestMove;
    }
};

// int minmax(TicTacToeGrid grid, int depth, bool player) {
//     if (depth == 0 || grid.isEndgame()) {
//         return H(grid);
//     }
//
//     if (player) {
//         int bestMove = INT_MIN;
//         std::vector<Move> moves = grid.getMoves();
//         for (auto it = moves.begin(); it != moves.end(); it++) {
//             TicTacToeGrid g = grid.makeMove(player, *it);
//             bestMove = std::max(bestMove, minmax(g, depth - 1, false));
//         }
//         return bestMove;
//
//     } else {
//         int bestMove = INT_MAX;
//         std::vector<Move> moves = grid.getMoves();
//         for (auto it = moves.begin(); it != moves.end(); it++) {
//             TicTacToeGrid g = grid.makeMove(player, *it);
//             bestMove = std::min(bestMove, minmax(g, depth - 1, true));
//         }
//         return bestMove;
//     }
// }
//
// Move minmaxRoot(TicTacToeGrid grid, int depth, bool player) {
//     Move bestMove = Move();
//     int bestValue = INT_MIN;
//     if (!grid.getTurn()) {
//         bestValue = INT_MAX;
//     }
//
//     std::vector<Move> moves = grid.getMoves();
//     for (auto it = moves.begin(); it != moves.end(); it++) {
//         TicTacToeGrid g = grid.makeMove(player, *it);
//         int value = minmax(g, depth - 1, !player);
//
//         if (player) {
//             if (value > bestValue) {
//                 bestValue = value;
//                 bestMove = *it;
//             }
//         } else {
//             if (value < bestValue) {
//                 bestValue = value;
//                 bestMove = *it;
//             }
//         }
//     }
//
//     return bestMove;
// }

Move getUserMove() {
    int pos[2];

    std::cout << "\nInsert row: ";

    std::cin >> pos[0];

    std::cout << "\nInsert col: ";

    std::cin >> pos[1];

    std::cout << std::endl;

    return Move(pos);
}

int main(void) {
    TicTacToeGrid grid;
    Algorithm algorithm(9);
    Move move;

    grid.print();
    std::cout << std::endl;

    while (!grid.isEndgame()) {
        bool turn = grid.getTurn();

        if (turn) {
            // move = getUserMove();
            move = algorithm.minmax(grid, turn);
        } else {
            // move = minmaxRoot(grid, 9, turn);
            move = algorithm.minmax(grid, turn);
        }

        grid = grid.makeMove(turn, move);

        grid.print();
        std::cout << std::endl;
    }

    return 0;
}
