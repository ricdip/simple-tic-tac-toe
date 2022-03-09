# Simple C++ Tic Tac Toe

A simple C++ implementation of the Tic Tac Toe game that uses the MinMax Algorithm for the AI implementation

## Implemented algorithms

- MinMax
- MinMax Alpha-Beta

## Implemented heuristics

- Game over heuristic:
    - we assign score `+1` if the max player wins
    - we assign score `-1` if the min player wins
    - we assign score `0` otherwise

## Building the application

`make build`

## Running the application

`./main.exe --depth <maxDepth> --mode <runningMode> --algorithm <algorithm>`

- The application has two running modes:
    - `ai_vs_ai`: both player are controlled by the AI
    - `player_vs_ai`: the first player is controlled by the Human, the second player is controlled by the AI

- The application has two usable algorithms:
    - `minmax`
    - `minmax_alpha_beta`

### Running examples
- Default setting (max depth = 9, mode = `ai_vs_ai`, algorithm = `minmax`)

`./main.exe`

- Custom setting (max depth = 2, mode = `player_vs_ai`, algorithm = `minmax_alpha_beta`)

`./main.exe --depth 2 --mode player_vs_ai --algorithm minmax_alpha_beta`

