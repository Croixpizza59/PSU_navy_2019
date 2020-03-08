/*
** EPITECH PROJECT, 2020
** navy
** File description:
** proto_navy
*/

#ifndef PROTO_NAVY
#define PROTO_NAVY

#include "struct.h"
#include "macro.h"
#include "proto_user2.h"
#include "proto_user1.h"
#include "proto_lib.h"

int navy_funct(navy_t *navy, int ac, char **av);
int map_maker(navy_t *navy);
char **init_map(navy_t *navy);
char **init_map_dup(navy_t *navy);
char **init_map_pos(navy_t *navy);
int create_map(navy_t *navy);
int create_map_dup(navy_t *navy);
int create_map_pos(navy_t *navy, char *map_pos);
bool replace_boat_positions(navy_t *navy);
bool display_map(navy_t *navy);
void display_map_sec(navy_t *navy);
int check_my_input(char *buffer);
int receive_signals(navy_t *navy);
bool checking_letter(navy_t *navy);
void hit_or_miss(navy_t *navy);
bool y_axes(navy_t *navy, int y, bool check);
bool x_axes(navy_t *navy, int y, bool check);
void my_free(navy_t *navy);
void my_free_pos(navy_t *navy);
bool checking_lenght(navy_t *navy);
bool check_my_formater(navy_t *navy);
int find_number(char buffer, int i);
int getstat(char const *filepath);
void draw_ennem_actions(navy_t *navy);

#endif