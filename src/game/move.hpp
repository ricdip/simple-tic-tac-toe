#ifndef MOVE_HPP
#define MOVE_HPP

class Move {
private:
  int position[2];
  int score;

public:
  Move(){};
  Move(int pos[2]);
  Move(int pos[2], int s);
  int *getPosition();
  void setPosition(int pos[2]);
  int getScore();
  void setScore(int s);
};

#endif
