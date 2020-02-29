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
    else if ((game->map.len = read(game->map.fd,
    game->map.buffer, game->map.size)) <= 0)
        return (84);
    game->map.map = init_map(game);
    display_map(game);
    return (0);
}

int create_map_pos(game_t *game)
{
    game->map.buffer_pos = NULL;
    game->map.x_max_pos = 8;
    game->map.y_max_pos = 4;

    if ((game->map.size_pos = getstat("pos1")) <= 0) {
        my_putstr("getstat failed\n");
        return (84);
    }
    else if (!(game->map.buffer_pos = malloc(sizeof(char) * (game->map.size_pos))))
        return (84);
    if ((game->map.fd_pos = open("pos1", O_RDONLY)) <= 0) {
        printf("open failed\n");
        return (84);
    }
    else if ((game->map.len_pos = read(game->map.fd_pos,
    game->map.buffer_pos, game->map.size_pos)) <= 0) {
        printf("read failed\n");
        return (84);
    }
    game->map.map_pos = init_map_pos(game);
    if (checking_letter(game) == true) {
        printf("error in pos1\n");
        return (84);
    }
    return (0);
}