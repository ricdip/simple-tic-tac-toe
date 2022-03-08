CC = g++
CFLAGS = -pedantic -Wall -Wextra -Werror
CFLAGSDEBUG = -pedantic -Wall -Wextra -Werror -fsanitize=address -g

SRC = move.cpp state.cpp heuristics.cpp algorithms.cpp game.cpp main.cpp
OBJ = main.exe
OBJDEBUG = main_debug.exe


.DEFAULT_GOAL: build

build: $(SRC)
	@echo "Building files..."
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

build_debug: $(SRC)
	@echo "Building files for debug..."
	$(CC) $(CFLAGSDEBUG) $(SRC) -o $(OBJDEBUG)

clean:
	@echo "Cleaning files..."
	rm -f $(OBJ)
	rm -f $(OBJDEBUG)
	rm -f $(OBJDEBUGGER)

run: build
	@echo "Running..."
	./$(OBJ)

run_debug: build_debug
	@echo "Running debug..."
	./$(OBJDEBUG)

all: clean build run clean


.PHONY: build build_debug clean run run_debug all
