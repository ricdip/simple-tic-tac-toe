#include "move.hpp"

Move::Move(int pos[2]) { setPosition(pos); }

Move::Move(int pos[2], int s) {
  setPosition(pos);
  score = s;
}

int *Move::getPosition() { return position; }

void Move::setPosition(int pos[2]) {
  position[0] = pos[0];
  position[1] = pos[1];
}

int Move::getScore() { return score; }

void Move::setScore(int s) { score = s; }
