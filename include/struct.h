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
    char *pos1;
    char *pos2;
    bool check;
    int count;
    int nb;
};

struct map
{
    char **map;
    char **map_pos;
    int x_max_pos;
    int y_max_pos;
    int x_max;
    int y_max;
    int fd;
    int fd_pos;
    int size;
    int size_pos;
    int len;
    int len_pos;
    char *buffer;
    char *buffer_pos;
};

struct game
{
    user_t user;
    map_t map;
};

#endif
