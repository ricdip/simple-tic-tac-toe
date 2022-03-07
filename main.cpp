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

Move max(Move lhs, Move rhs) {
    if (lhs.getScore() >= rhs.getScore()) {
        return lhs;
    } else {
        return rhs;
    }
}

Move min(Move lhs, Move rhs) {
    if (lhs.getScore() <= rhs.getScore()) {
        return lhs;
    } else {
        return rhs;
    }
}

class TicTacToeGrid {
   private:
    // clang-format off
    char grid[ROWS][COLS] = {
        OO, OO, OO,
        OO, OO, OO,
        OO, OO, OO,
    };

    bool turn = true;
    Move lastMove = Move();
    // clang-format on

   public:
    TicTacToeGrid();
    TicTacToeGrid(char g[ROWS][COLS], bool t);
    void print();
    bool getTurn();
    TicTacToeGrid& makeMove(bool player, int position[2]);
    std::vector<Move> getMoves();
    bool isEndgame();
    char victoryPlayer();
    Move getLastMove();
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

TicTacToeGrid& TicTacToeGrid::makeMove(bool player, int position[2]) {
    TicTacToeGrid* newGrid = new TicTacToeGrid(grid, !player);
    if (player) {
        newGrid->grid[position[0]][position[1]] = P1;
    } else {
        newGrid->grid[position[0]][position[1]] = P2;
    }

    lastMove = Move(position);

    return *newGrid;
}

std::vector<Move> TicTacToeGrid::getMoves() {
    std::vector<Move> moves = std::vector<Move>();

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == OO) {
                moves.push_back(Move(new int[2]{i, j}));
            }
        }
    }

    return moves;
}

bool TicTacToeGrid::isEndgame() {
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

Move TicTacToeGrid::getLastMove() { return lastMove; }

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

int minmax(TicTacToeGrid grid, int depth, bool player) {
    if (depth == 0 || grid.isEndgame()) {
        return H(grid);
    }

    if (player) {
        int bestMove = INT_MIN;
        std::vector<Move> moves = grid.getMoves();
        for (auto it = moves.begin(); it != moves.end(); it++) {
            TicTacToeGrid g = grid.makeMove(player, it->getPosition());
            bestMove = std::max(bestMove, minmax(g, depth - 1, false));
        }
        return bestMove;

    } else {
        int bestMove = INT_MAX;
        std::vector<Move> moves = grid.getMoves();
        for (auto it = moves.begin(); it != moves.end(); it++) {
            TicTacToeGrid g = grid.makeMove(player, it->getPosition());
            bestMove = std::min(bestMove, minmax(g, depth - 1, true));
        }
        return bestMove;
    }
}

Move minmaxRoot(TicTacToeGrid grid, int depth, bool player) {
    int bestValue = INT_MAX;
    Move bestMove = Move();
    if (!grid.getTurn()) {
        bestValue = INT_MIN;
    }

    std::vector<Move> moves = grid.getMoves();
    for (auto it = moves.begin(); it != moves.end(); it++) {
        TicTacToeGrid g = grid.makeMove(player, it->getPosition());
        int value = minmax(g, depth - 1, !player);

        if (player) {
            if (value > bestValue) {
                bestValue = value;
                bestMove = *it;
            }
        } else {
            if (value < bestValue) {
                bestValue = value;
                bestMove = *it;
            }
        }
    }

    return bestMove;
}

int main(void) {
    TicTacToeGrid grid;

    while (!grid.isEndgame()) {
        bool turn = grid.getTurn();

        std::cout << "pre-move" << std::endl;
        grid.print();

        Move m = minmaxRoot(grid, 9, turn);

        std::cout << "score: " << m.getScore() << std::endl;

        // grid = grid.makeMove(turn, grid.getMoves()[0].getPosition());
        grid = grid.makeMove(turn, m.getPosition());

        std::cout << "post-move" << std::endl;
        grid.print();

        std::cout << "------------------------" << std::endl;
        std::cout << std::endl;
    }

    // std::cout << m.getPosition()[0] << "," << m.getPosition()[1] <<
    // std::endl; std::cout << m.getScore() << std::endl;

    // std::vector<Move> moves = grid.getMoves();

    // for (auto it = moves.begin(); it != moves.end(); it++) {
    //     std::cout << (it->getPosition()[0]) << "," << (it->getPosition()[1])
    //               << std::endl;
    // }

    // std::cout << std::endl;

    // grid = grid.makeMove(true, new int[2]{0, 0});

    // std::vector<Move> moves_2 = grid.getMoves();

    // for (auto it = moves_2.begin(); it != moves_2.end(); it++) {
    //     std::cout << (it->getPosition()[0]) << "," << (it->getPosition()[1])
    //               << std::endl;
    // }

    return 0;
}
