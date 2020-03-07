/*
** EPITECH PROJECT, 2020
** create_map.c
** File description:
** create_map
*/

#include "proto.h"

int create_map(game_t *game)
{
    game->map.buffer = NULL;
    game->map.x_max = 17;
    game->map.y_max = 10;

    if ((game->map.size = getstat("./rsc/map.txt")) <= 0)
        return (84);
    else if (!(game->map.buffer = malloc(sizeof(char) * (game->map.size))))
        return (84);
    if ((game->map.fd = open("./rsc/map.txt", O_RDONLY)) <= 0)
        return (84);
    else if ((game->map.len = read(game->map.fd, game->map.buffer,
    game->map.size)) <= 0)
        return (84);
    game->map.map = init_map(game);
    return (0);
}

int create_map_sec(game_t *game)
{
    game->map.buffer2 = NULL;
    game->map.x_max = 17;
    game->map.y_max = 10;

    if ((game->map.size2 = getstat("./rsc/map_sec.txt")) <= 0)
        return (84);
    else if (!(game->map.buffer2 = malloc(sizeof(char) * (game->map.size2))))
        return (84);
    if ((game->map.fd2 = open("./rsc/map_sec.txt", O_RDONLY)) <= 0)
        return (84);
    else if ((game->map.len2 = read(game->map.fd2, game->map.buffer2,
    game->map.size2)) <= 0)
        return (84);
    game->map.map2 = init_map_sec(game);
    return (0);
}