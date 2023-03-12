#include "heuristics.hpp"

int H(TicTacToeState state) {
  char winner = state.victoryPlayer();
  if (winner == P1) {
    return 1;
  } else if (winner == P2) {
    return -1;
  } else {
    return 0;
  }
}
