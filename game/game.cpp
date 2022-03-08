#include "game.hpp"

#include <iostream>

#include "../algorithms/algorithms.hpp"
#include "state.hpp"

Move TicTacToeGame::getPlayerMove() {
    int pos[2];

    std::cout << "\nInsert row: ";

    std::cin >> pos[0];

    std::cout << "\nInsert col: ";

    std::cin >> pos[1];

    std::cout << std::endl;

    return Move(pos);
}

void TicTacToeGame::AIvsAI(int maxDepth) {
    TicTacToeState state;
    Algorithm algorithm(maxDepth);
    Move move;

    state.print();
    std::cout << std::endl;

    while (!state.isEndgame()) {
        bool turn = state.getTurn();

        move = algorithm.minmax(state, turn);

        state = state.makeMove(turn, move);

        state.print();
        std::cout << std::endl;
    }
}

void TicTacToeGame::PlayervsAI(int maxDepth) {
    TicTacToeState state;
    Algorithm algorithm(maxDepth);
    Move move;

    state.print();
    std::cout << std::endl;

    while (!state.isEndgame()) {
        bool turn = state.getTurn();

        if (turn) {
            move = getPlayerMove();
        } else {
            move = algorithm.minmax(state, turn);
        }

        state = state.makeMove(turn, move);

        state.print();
        std::cout << std::endl;
    }
}
