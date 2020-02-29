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

#define RAM 2048

/* user signal */
int user1(game_t *game);
int user2(game_t *game, char *pid1);

/* signal_handling */
void sig_handler(int i, siginfo_t *sig, void *test);

/* main functions */
int main(int ac, char **av);
int navy(game_t *game, int ac, char **av);
void helper();

/* create map game */
int getstat(char const *filepath);
int create_map(game_t *game);
char **init_map(game_t *game);
void display_map(game_t *game);

/* create map pos */
int create_map_pos(game_t *game);
char **init_map_pos(game_t *game);

bool checking_letter(game_t *game);
void my_free_pos(game_t *game);

#endif