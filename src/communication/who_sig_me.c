/*
** EPITECH PROJECT, 2020
** who_sig_me
** File description:
** programm display for eatch signals name and pid
*/

#include "proto.h"

void who_sig_me(int one, int sec, pid_t pid)
{
    strsignal(one);
    strsignal(sec);
    //printf("Signal %s\n%s\n received from %d", str, str_sec, pid);
}