# compiler options
CC = g++
CFLAGS = -pedantic -Wall -Wextra -Werror
CFLAGSDEBUG = -pedantic -Wall -Wextra -Werror -fsanitize=address -g

# sources and objects
SRC = $(shell fd --type f -e cpp)
FILES = $(shell fd --type f -e cpp -e hpp)
OBJ = main.exe
OBJDEBUG = main_debug.exe
