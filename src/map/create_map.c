/*
** EPITECH PROJECT, 2020
** navy
** File description:
** create all game maps
*/

#include "proto.h"

int create_map(navy_t *navy)
{
    navy->map.buffer = NULL;
    navy->map.x_max = 17;
    navy->map.y_max = 10;

    if ((navy->map.size = getstat("./rsc/map.txt")) <= 0)
        return (84);
    else if (!(navy->map.buffer = malloc(sizeof(char) * (navy->map.size))))
        return (84);
    if ((navy->map.fd = open("./rsc/map.txt", O_RDONLY)) <= 0)
        return (84);
    else if ((navy->map.len = read(navy->map.fd, navy->map.buffer,
    navy->map.size)) <= 0)
        return (84);
    navy->map.map = init_map(navy);
    return (0);
}

int create_map_dup(navy_t *navy)
{
    navy->map.buffer_dup = NULL;
    navy->map.x_max = 17;
    navy->map.y_max = 10;

    if ((navy->map.size_dup = getstat("./rsc/map_sec.txt")) <= 0)
        return (84);
    else if (!(navy->map.buffer_dup = malloc(sizeof(char) *
    (navy->map.size_dup))))
        return (84);
    if ((navy->map.fd_dup = open("./rsc/map_sec.txt", O_RDONLY)) <= 0)
        return (84);
    else if ((navy->map.len_dup = read(navy->map.fd_dup, navy->map.buffer_dup,
    navy->map.size_dup)) <= 0)
        return (84);
    navy->map.map_dup = init_map_dup(navy);
    return (0);
}