#include <chrono>
#include <cstring>
#include <iostream>

#include "game/game.hpp"

#define AI_VS_AI false
#define PLAYER_VS_AI true

struct Args {
    int maxDepth;
    bool mode;
    std::string algorithm;
};

Args parseArgs(int argc, char* argv[]) {
    if (argc > 1) {
        int maxDepth = 9;
        bool mode = false;
        std::string algorithm = "minmax";

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
            } else if (strcmp(argv[i], "--algorithm") == 0) {
                algorithm = argv[i + 1];
            }
        }
        return Args{maxDepth, mode, algorithm};

    } else {
        // default args:
        //  - maxDepth = 9
        //  - mode  = AIvsAI
        //  - algorithm = MinMax
        return Args{9, false, "minmax"};
    }
}

int main(int argc, char* argv[]) {
    TicTacToeGame game;

    Args parsedArgs = parseArgs(argc, argv);

    std::cout << std::endl;
    std::cout << "- max depth: " << parsedArgs.maxDepth << std::endl;
    std::cout << "- mode     : "
              << ((parsedArgs.mode) ? "player_vs_ai" : "ai_vs_ai") << std::endl;
    std::cout << "- algorithm: " << parsedArgs.algorithm << std::endl;
    std::cout << std::endl;

    if (parsedArgs.mode == AI_VS_AI) {
        // Tic Tac Toe AI vs AI mode
        auto start = std::chrono::steady_clock::now();
        game.AIvsAI(parsedArgs.algorithm, parsedArgs.maxDepth);
        auto end = std::chrono::steady_clock::now();

        auto diff =
            std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                .count();

        std::cout << std::endl;
        std::cout << "- elapsed time: " << diff << " ms" << std::endl;

    } else if (parsedArgs.mode == PLAYER_VS_AI) {
        // Tic Tac Toe Player vs AI mode
        game.PlayervsAI(parsedArgs.algorithm, parsedArgs.maxDepth);
    }

    return 0;
}
