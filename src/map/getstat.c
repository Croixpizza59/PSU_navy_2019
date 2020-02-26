/*
** EPITECH PROJECT, 2020
** getstats.c
** File description:
** getstat
*/

#include "proto.h"

int getstat(char const *filepath)
{
    struct stat buf = {0};

    stat(filepath, &buf);
    return (buf.st_size);
}