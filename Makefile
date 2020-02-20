##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

LIB_DIR = ./lib/

SRC_DIR = ./src/
SRC_COM = ./src/communication/
SRC_MAP = ./src/map/
SRC_GAME = ./src/gameplay/

TEST = tests/tests.c	\

SRC =	$(SRC_COM)process_info.c	\
		$(SRC_COM)kill_it.c	\
		$(SRC_COM)who_sig_me.c	\
		$(SRC_COM)signal_handler.c	\

SRC_BUILD	=	$(SRC) $(SRC_DIR)main.c

NAME = navy

TEST_BIN = unit_tests

CFLAGS = -Wall -Wextra -I./include/ -I./lib/

OBJ	=	$(SRC_BUILD:.c=.o)

OBJ_TESTS	=	$(SRC:.c=.o)

all: $(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L $(LIB_DIR) -lmy

tests_run: CFLAGS += --coverage
tests_run: $(OBJ_TESTS)
		make -C $(LIB_DIR)
		gcc -o $(TEST_BIN) $(OBJ_TESTS) $(TEST) -L $(LIB_DIR) -lmy $(CFLAGS) -lcriterion --coverage
		./$(TEST_BIN)
		gcovr --exclude tests --print-summary

debug: CFLAGS += -g
debug: re

clean:
	rm -f $(LIB_DIR)*.a
	rm -f $(LIB_DIR)*.o
	rm -f $(SRC_DIR)*.gc*
	rm -f $(SRC_DIR)*.o
	rm -f $(SRC_COM)*.o
	rm -f $(SRC_COM)*.gc*
	rm -f $(SRC_GAME)*.o
	rm -f $(SRC_GAME)*.gc*
	rm -f $(SRC_MAP)*.o
	rm -f $(SRC_MAP)*.gc*

fclean: clean
	rm -f $(TEST_BIN)
	rm -f $(TEST_BIN)
	rm -f $(NAME)

re: fclean all
