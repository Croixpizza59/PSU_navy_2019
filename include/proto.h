/*
** EPITECH PROJECT, 2020
** proto
** File description:
** proto
*/

#ifndef PROTO_NAVY
#define PROTO_NAVY

#include "struct.h"
#include "proto_lib.h"
#include "macro.h"

/* user signal */
int user1(game_t *game);
int user2(game_t *game, char *pid1);

/* signal_handling */
void sig_handler(int i, siginfo_t *sig, void *test);

/* main functions */
int main(int ac, char **av);
int navy(game_t *game, int ac, char **av);
void helper();

/* origin map game */
int getstat(char const *filepath);
int create_map(game_t *game);
char **init_map(game_t *game);
bool display_map(game_t *game);
bool find_my_position(game_t *game);

/* map pos */
int create_map_pos(game_t *game, char *map_pos);
char **init_map_pos(game_t *game);
int checking_board(game_t *game, int x, int y, int i);
int basics_actions(game_t *game, char *map_pos);
void display_map_sec(game_t *game);

/* error_handling */
bool check_my_formater(game_t *game);
bool checking_letter(game_t *game);
void my_free_pos(game_t *game);
void my_free(game_t *game);

// axes positions
bool x_axes(game_t *game, int y, bool check);
bool y_axes(game_t *game, int y, bool check);

// game
int check_my_buffer(game_t *game, char *buffer);
int main_game(game_t *game);
int signal_checking(game_t *game, char buffer, char buffer_sec);

#endif
