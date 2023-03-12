#ifndef GAME_HPP
#define GAME_HPP

#include <string>

#include "move.hpp"

class TicTacToeGame {
public:
  Move getPlayerMove();

  void AIvsAI(std::string algorithm, int maxDepth);

  void PlayervsAI(std::string algorithm, int maxDepth);
};

#endif
