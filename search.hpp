#include "heuristics.hpp"

class Move {
   private:
    int* position;
    int score;

   public:
    Move() {}
    Move(int* p, int s) {
        position = p;
        score = s;
    }
    int getScore() const { return score; }
    int* getPosition() const { return position; }
};

const Move& max(const Move& m1, const Move& m2);

const Move& min(const Move& m1, const Move& m2);

Move minmax(TicTacToeGrid grid, int depth, bool player);
