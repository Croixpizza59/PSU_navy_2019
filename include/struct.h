/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct navy
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct game game_t;
typedef struct user user_t;
typedef struct map map_t;
typedef struct pos pos_t;
typedef struct coord coord_t;

struct user
{
    int pid_ennemy;
    int pid_user1;
    int pid_user2;
    char *pos;
    bool check;
    int count;
    int nb;
    int crypt;
    int crypt_sec;
    char *receptor;
    char *type;
};

struct map
{
    char **map;
    char **map2;
    char **map_pos;
    int x_max_pos;
    int y_max_pos;
    int x_max;
    int y_max;
    int fd;
    int fd2;
    int fd_pos;
    int size;
    int size2;
    int size_pos;
    int len;
    int len2;
    int len_pos;
    char *buffer;
    char *buffer2;
    char *buffer_pos;
};

struct pos
{
    int nb;
    int i;
    int j;
    int k;
    int a;
    int count1;
    int count2;
    int check;
};

struct coord
{
    int lines;
    int cols;
};

struct game
{
    user_t user;
    map_t map;
    pos_t pos;
    coord_t coord;
};

#endif
