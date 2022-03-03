#include <vector>

#define ROWS 3
#define COLS 3

#define OO '.'
#define P1 'X'
#define P2 'O'

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
    void print();
    bool getTurn();
    TicTacToeGrid& makeMove(bool player, int position[2]);
    std::vector<int*> getMoves();
    bool is_endgame();
    char victory_player();
};
