/*
** EPITECH PROJECT, 2020
** create_map.c
** File description:
** create_map
*/

#include "proto.h"

int create_map(game_t *game)
{
    int fd = 0;
    int len = 0;
    int size = 0;
    char *buffer = NULL;
    game->map.x_max = 17;
    game->map.y_max = 10;

    if ((size = getstat("./rsc/map.txt")) <= 0)
        return (84);
    else if (!(buffer = malloc(sizeof(char) * (size))))
        return (84);
    if ((fd = open("./rsc/map.txt", O_RDONLY)) <= 0)
        return (84);
    else if ((len = read(fd, buffer, size)) <= 0)
        return (84);
    game->map.map = init_map(game, buffer, len);
    display_map(game);
    return (0);
}