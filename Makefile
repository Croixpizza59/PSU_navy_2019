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

TEST = tests/tests.c	\

SRC	=	$(SRC_MAP)create_map.c	\
		$(SRC_MAP)getstat.c	\
		$(SRC_MAP)init_map.c	\
		$(SRC_MAP)display_map.c

SRC_BUILD	=	$(SRC) $(SRC_DIR)main.c

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
	@rm -f $(LIB_DIR)*.a
	@rm -f $(LIB_DIR)*.o
	@rm -f $(SRC_DIR)*.gc*
	@rm -f $(SRC_DIR)*.o
	@rm -f $(SRC_COM)*.o
	@rm -f $(SRC_COM)*.gc*
	@rm -f $(SRC_GAME)*.o
	@rm -f $(SRC_GAME)*.gc*
	@rm -f $(SRC_MAP)*.o
	@rm -f $(SRC_MAP)*.gc*

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