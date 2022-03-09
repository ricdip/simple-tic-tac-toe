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

void TicTacToeGame::AIvsAI(std::string algorithm, int maxDepth) {
    TicTacToeState state;
    Algorithm searchAlgorithm(maxDepth);
    Move move;

    state.print();
    std::cout << std::endl;

    while (!state.isEndgame()) {
        bool turn = state.getTurn();

        if (algorithm == MINMAX) {
            move = searchAlgorithm.minmax(state, turn);

        } else if (algorithm == MINMAX_ALPHA_BETA) {
            move = searchAlgorithm.minmaxAlphaBeta(state, turn);

        } else {
            throw "Illegal search algorithm";
        }

        state = state.makeMove(turn, move);

        state.print();
        std::cout << std::endl;
    }
}

void TicTacToeGame::PlayervsAI(std::string algorithm, int maxDepth) {
    TicTacToeState state;
    Algorithm searchAlgorithm(maxDepth);
    Move move;

    state.print();
    std::cout << std::endl;

    while (!state.isEndgame()) {
        bool turn = state.getTurn();

        if (turn) {
            move = getPlayerMove();
        } else {
            if (algorithm == MINMAX) {
                move = searchAlgorithm.minmax(state, turn);

            } else if (algorithm == MINMAX_ALPHA_BETA) {
                move = searchAlgorithm.minmaxAlphaBeta(state, turn);

            } else {
                throw "Illegal search algorithm";
            }
        }

        state = state.makeMove(turn, move);

        state.print();
        std::cout << std::endl;
    }
}
