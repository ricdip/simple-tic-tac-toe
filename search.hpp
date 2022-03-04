#include "heuristics.hpp"

const Move& max(const Move& m1, const Move& m2);

const Move& min(const Move& m1, const Move& m2);

Move minmax(TicTacToeGrid grid, int depth, bool player);
