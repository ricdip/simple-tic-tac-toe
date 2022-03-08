#include "game.hpp"

#include <iostream>

#include "algorithms.hpp"
#include "state.hpp"

Move getUserMove() {
    int pos[2];

    std::cout << "\nInsert row: ";

    std::cin >> pos[0];

    std::cout << "\nInsert col: ";

    std::cin >> pos[1];

    std::cout << std::endl;

    return Move(pos);
}

void AIvsAI(int d) {
    TicTacToeState state;
    Algorithm algorithm(d);
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

void PlayervsAI(int d) {
    TicTacToeState state;
    Algorithm algorithm(d);
    Move move;

    state.print();
    std::cout << std::endl;

    while (!state.isEndgame()) {
        bool turn = state.getTurn();

        if (turn) {
            move = getUserMove();
        } else {
            move = algorithm.minmax(state, turn);
        }

        state = state.makeMove(turn, move);

        state.print();
        std::cout << std::endl;
    }
}
