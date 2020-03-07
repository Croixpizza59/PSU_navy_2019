/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** proto navy
*/

#ifndef PROTO_H
#define PROTO_H

#include "struct.h"
#include "proto_lib.h"
#include "macro.h"

extern int global;

    //main functions//
int main(int ac, char **av);
void helper(void);
void my_free_pos(game_t *game);
void my_free(game_t *game);
int navy(game_t *game, int ac, char **av);

    //connection functions//
int user1(game_t *game);
int prepare_my_user1(game_t *game);
void sig_handler(int i, siginfo_t *sig, void *test);
int prepare_my_user2(game_t *game, char *pid1);
int user2(game_t *game, char *pid1);

    //map proto//
int getstat(char const *filepath);
char **init_map(game_t *game);
int create_map(game_t *game);
int create_map_pos(game_t *game, char *map_pos);
bool find_my_position(game_t *game);
bool x_axes(game_t *game, int y, bool check);
bool y_axes(game_t *game, int y, bool check);
bool display_map(game_t *game);
void display_map_sec(game_t *game);
int create_map_sec(game_t *game);

    //checking//
bool checking_letter(game_t *game);
bool check_my_formater(game_t *game);
int signal_checking(game_t *game, char buffer, char buffer_sec);
int check_my_buffer(char *buffer);
int main_game_sec(game_t *game);
int main_game(game_t *game);
int signal_checking_sec(game_t *game, char buffer, char buffer_sec);
int before_check_sec(char buffer, int i);
char **init_map_sec(game_t *game);
char find_letter(char buffer, int i);
void print_values(char letter, int nb, char *str);

    //assignment//
void map_assignment_user1(game_t *game);
void map_assignment_user2(game_t *game);
int receive_signal(game_t *game);
void sig_handler_sec(int signal, siginfo_t *sig, void *test);
void who_kill_who(game_t *game);

// who win
int who_win_user1(game_t *game);
int who_win_user2(game_t *game);
int recept_win(void);
#endif
