##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

DEBUG_THEME	=	$(YELLO_C)
COLOR_THEME	=	$(CYAN_C)
JUNGLE_THEME	=	$(RED_C)

LIB_DIR = ./lib/

SRC_DIR = ./src/
SRC_COM = ./src/comm/
SRC_MAP = ./src/map/
SRC_GAME = ./src/gameplay/
SRC_MAIN = ./src/main_functions/
SRC_CHECK = ./src/checking/
SRC_POS = ./src/map/pos/
SRC_ORIGIN = ./src/map/origin/
SRC_GAME = ./src/game/

TEST = tests/tests.c	\

SRC	=	$(SRC_ORIGIN)create_map.c	\
		$(SRC_ORIGIN)getstat.c	\
		$(SRC_ORIGIN)init_map.c	\
		$(SRC_ORIGIN)display_map.c	\
		$(SRC_MAIN)navy.c	\
		$(SRC_MAIN)helper.c	\
		$(SRC_MAIN)free.c	\
		$(SRC_CHECK)checking.c	\
		$(SRC_CHECK)checking_format.c	\
		$(SRC_POS)create_map_pos.c	\
		$(SRC_POS)init_map_pos.c	\
		$(SRC_COM)user1.c	\
		$(SRC_COM)user2.c	\
		$(SRC_POS)find_my_positions.c	\
		$(SRC_POS)checking_board.c	\
		$(SRC_POS)axes.c	\
		$(SRC_POS)display_map_sec.c	\
		$(SRC_POS)basics_actions.c	\
		$(SRC_GAME)main_game.c	\
		$(SRC_GAME)check_my_buffer.c	\

SRC_BUILD	=	$(SRC) $(SRC_MAIN)main.c

NAME = navy

TEST_BIN = unit_tests

CFLAGS = -Wall -Wextra -I./include/ -I./lib/

OBJ	=	$(SRC_BUILD:.c=.o)

OBJ_TESTS	=	$(SRC:.c=.o)

all: $(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L $(LIB_DIR) -lmy

	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" __   _       ___   _     _  __    __"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|  \ | |     /   | | |   / / \ \  / /"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|   \| |    / /| | | |  / /   \ \/ /"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |\   |   / / | | | | / /     \  / "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| | \  |  / /  | | | |/ /      / / "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|_|  \_| /_/   |_| |___/      /_/"$(DEFAULT)
	@$(LINE_RETURN)

tests_run: CFLAGS += --coverage
tests_run: $(OBJ_TESTS)
		make -C $(LIB_DIR)
		gcc -o $(TEST_BIN) $(OBJ_TESTS) $(TEST) -L $(LIB_DIR) -lmy $(CFLAGS) -lcriterion --coverage
		./$(TEST_BIN)
		gcovr --exclude tests --print-summary

debug: CFLAGS += -g
debug: re

	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(DEBUG_THEME)"_____   _____   _____   _   _   _____  "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(DEBUG_THEME)"|  _  \ | ____| |  _  \ | | | | /  ___| "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(DEBUG_THEME)"| | | | | |__   | |_| | | | | | | |     "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(DEBUG_THEME)"| | | | |  __|  |  _  { | | | | | |  _  "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(DEBUG_THEME)"| |_| | | |___  | |_| | | |_| | | |_| | "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(DEBUG_THEME)"|_____/ |_____| |_____/ \_____/ \_____/ "$(DEFAULT)
	@$(LINE_RETURN)

clean:
	@rm -f $(OBJ)
	@rm -f $(LIB_DIR)*.a
	@rm -f $(SRC_DIR)*.gc*
	@rm -f $(SRC_COM)*.gc*
	@rm -f $(SRC_GAME)*.gc*
	@rm -f $(SRC_MAP)*.gc*
	@rm -f $(LIB_DIR)*.o

	@$(LINE_RETURN)
	@$(ECHO) $(DIM_T)$(COLOR_THEME)" _____   _       _____       ___   __   _  "$(DEFAULT)
	@$(ECHO) $(DIM_T)$(COLOR_THEME)"/  ___| | |     | ____|     /   | |  \ | | "$(DEFAULT)
	@$(ECHO) $(DIM_T)$(COLOR_THEME)"| |     | |     | |__      / /| | |   \| | "$(DEFAULT)
	@$(ECHO) $(DIM_T)$(COLOR_THEME)"| |     | |     |  __|    / / | | | |\   | "$(DEFAULT)
	@$(ECHO) $(DIM_T)$(COLOR_THEME)"| |___  | |___  | |___   / /  | | | | \  | "$(DEFAULT)
	@$(ECHO) $(DIM_T)$(COLOR_THEME)"\_____| |_____| |_____| /_/   |_| |_|  \_| "$(DEFAULT)
	@$(LINE_RETURN)

fclean: clean
	@rm -f $(TEST_BIN)
	@rm -f $(TEST_BIN)
	@rm -f $(NAME)

re: fclean all
