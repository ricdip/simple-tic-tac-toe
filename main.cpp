#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "game/game.hpp"

#define AI_VS_AI false
#define PLAYER_VS_AI true

struct Args {
    int maxDepth;
    bool mode;
};

Args parseArgs(int argc, char* argv[]) {
    if (argc > 1) {
        int maxDepth = 9;
        bool mode = false;

        for (int i = 0; i < argc; i++) {
            if (strcmp(argv[i], "--depth") == 0) {
                maxDepth = std::atoi(argv[i + 1]);
            } else if (strcmp(argv[i], "--mode") == 0) {
                if (strcmp(argv[i + 1], "ai_vs_ai") == 0) {
                    mode = false;

                } else if (strcmp(argv[i + 1], "player_vs_ai") == 0) {
                    mode = true;

                } else {
                    throw "Illegal mode";
                }
            }
        }
        return Args{maxDepth, mode};

    } else {
        // default args:
        //  - depth = 9
        //  - mode  = AIvsAI
        return Args{9, false};
    }
}

int main(int argc, char* argv[]) {
    TicTacToeGame game;

    Args parsedArgs = parseArgs(argc, argv);

    if (parsedArgs.mode == AI_VS_AI) {
        // Tic Tac Toe AI vs AI mode
        game.AIvsAI(parsedArgs.maxDepth);

    } else if (parsedArgs.mode == PLAYER_VS_AI) {
        // Tic Tac Toe Player vs AI mode
        game.PlayervsAI(parsedArgs.maxDepth);
    }

    return 0;
}
