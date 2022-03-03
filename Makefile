CC = g++
CFLAGS = -pedantic -Wall -Wextra -Werror
CFLAGSDEBUG = -pedantic -Wall -Wextra -Werror -fsanitize=address -g
SRC = board.cpp
OBJ = board.exe
OBJDEBUG = board_debug.exe

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

run:
	./$(OBJ)

all: build run

.PHONY: clean run all
