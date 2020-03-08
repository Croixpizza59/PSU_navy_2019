/*
** EPITECH PROJECT, 2020
** navy
** File description:
** structure for navy project
*/

#ifndef NAVY_STRUCT
#define NAVY_STRUCT

typedef struct navy navy_t;
typedef struct user1 user1_t;
typedef struct user2 user2_t;
typedef struct coord coord_t;
typedef struct map_pos map_pos_t;
typedef struct map map_t;
typedef struct verif verif_t;
typedef struct pos pos_t;


struct verif
{
    int pid_ennemy;
    int check;
};

struct user1
{
    int pid_user2;
};

struct user2
{
    int pid_user1;
};

struct coord
{
    int crypt;
    int crypt_sec;
    int lines;
    int cols;
};

struct map_pos
{
    char **map2;
    char *pos;
    int len_2;
    char *buffer_2;
    int size_2;
    int fd_2;
    int x_max_2;
    int y_max_2;

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
};

struct map
{
    char **map;
    char **map_dup;
    int len;
    int len_dup;
    int size;
    int size_dup;
    char *buffer;
    char *buffer_dup;
    int fd;
    int fd_dup;
    int x_max;
    int y_max;
};

struct navy
{
    user1_t user1;
    user2_t user2;
    coord_t coord;
    map_pos_t map_pos;
    map_t map;
    verif_t verif;
    pos_t pos;
};

#endif