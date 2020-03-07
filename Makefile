##
## EPITECH PROJECT, 2020
## navy
## File description:
## Makefile navy
##

LIB_DIR = ./lib/

SRC_CHK	=	./src/checking/
SRC_GAME	=	./src/game/
SRC_INIT	=	./src/init_user/
SRC_MAIN	=	./src/main_functions/
SRC_MAP_BAS	=	./src/map/basic/
SRC_MAP_POS	=	./src/map/map_pos/

TEST = tests/tests.c	\

SRC	=	$(SRC_CHK)check_letter.c	\
		$(SRC_CHK)checking_format.c	\
		$(SRC_GAME)check_my_buffer.c	\
		$(SRC_GAME)main_game_sec.c	\
		$(SRC_GAME)main_game.c	\
		$(SRC_GAME)map_assigment.c	\
		$(SRC_GAME)receive_signals.c	\
		$(SRC_GAME)signal_checking_sec.c	\
		$(SRC_GAME)signals_checking.c	\
		$(SRC_INIT)connect_user1.c	\
		$(SRC_INIT)user1.c	\
		$(SRC_INIT)user2.c	\
		$(SRC_MAIN)helper.c	\
		$(SRC_MAIN)my_free.c	\
		$(SRC_MAIN)navy.c	\
		$(SRC_MAP_BAS)create_map.c	\
		$(SRC_MAP_BAS)display_map.c	\
		$(SRC_MAP_BAS)getstat.c	\
		$(SRC_MAP_BAS)init_map.c	\
		$(SRC_MAP_POS)axes.c	\
		$(SRC_MAP_POS)create_map_pos.c	\
		$(SRC_MAP_POS)display_map_sec.c	\
		$(SRC_MAP_POS)find_positions.c	\
		$(SRC_GAME)who_kill_who.c	\
		$(SRC_GAME)who_win.c	\
		$(SRC_GAME)recept_win.c	\
		$(SRC_CHK)checking_lenght.c	\

SRC_BUILD	=	$(SRC) $(SRC_MAIN)main.c

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
	@rm -f $(SRC_COM)*.gc*
	@rm -f $(SRC_GAME)*.gc*
	@rm -f $(SRC_MAP)*.gc*
	@rm -f $(LIB_DIR)*.o

fclean: clean
	@rm -f $(TEST_BIN)
	@rm -f $(TEST_BIN)
	@rm -f $(NAME)

re: fclean all