##
## EPITECH PROJECT, 2020
## navy
## File description:
## Makefile navy
##

LIB_DIR = ./lib/

TEST = tests/tests.c	\

SRC_DIR = ./src/
SRC_CHK = ./src/checking_boat/
SRC_GAME = ./src/game/
SRC_MAP = ./src/map/
SRC_PLAY = ./src/player/

SRC	=	$(SRC_CHK)checking_letter.c	\
		$(SRC_CHK)checking_lenght.c	\
		$(SRC_CHK)checking_format.c	\
		$(SRC_GAME)check_my_input.c	\
		$(SRC_GAME)get_input.c	\
		$(SRC_GAME)hit_or_miss.c	\
		$(SRC_GAME)map_stocking.c	\
		$(SRC_GAME)receive_signals.c	\
		$(SRC_GAME)replace_boat_positions.c	\
		$(SRC_GAME)signal_sending_user1.c	\
		$(SRC_GAME)signal_sending_user2.c	\
		$(SRC_MAP)axes.c	\
		$(SRC_MAP)create_map_pos.c	\
		$(SRC_MAP)create_map.c	\
		$(SRC_MAP)display_map.c	\
		$(SRC_MAP)getstat.c	\
		$(SRC_MAP)init_map_pos.c	\
		$(SRC_MAP)init_map.c	\
		$(SRC_MAP)map_maker.c	\
		$(SRC_PLAY)first_connection.c	\
		$(SRC_PLAY)player_1_funct.c	\
		$(SRC_PLAY)player_2_funct.c	\
		$(SRC_DIR)navy_funct.c	\
		$(SRC_DIR)my_free.c	\

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
	@rm -f $(OBJ)
	@rm -f $(LIB_DIR)*.a
	@rm -f $(SRC_DIR)*.gc*
	@rm -f $(SRC_PLAY)*.gc*
	@rm -f $(SRC_GAME)*.gc*
	@rm -f $(SRC_MAP)*.gc*
	@rm -f $(LIB_DIR)*.o

fclean: clean
	@rm -f $(TEST_BIN)
	@rm -f $(TEST_BIN)
	@rm -f $(NAME)

re: fclean all