/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_NAVY
#define STRUCT_NAVY

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct user user_t;
typedef struct game game_t;
typedef struct map map_t;

struct user
{
    int pid_ennemy;
};

struct map
{
    char **map;
    int x_max;
    int y_max;
};

struct game
{
    user_t user;
    map_t map;
};

#endif