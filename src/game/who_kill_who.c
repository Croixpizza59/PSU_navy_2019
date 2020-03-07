/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** who_kill_who
*/

#include "proto.h"

void print_values(char letter, int nb, char *str)
{
    my_putchar(letter);
    my_putstr(show_number(nb));
    my_putstr(": ");
    my_putstr(str);
    my_putstr("\n\n");
}

char find_letter(char buffer, int i)
{
    if (i == 2)
        buffer = 'A';
    if (i == 4)
        buffer = 'B';
    if (i == 6)
        buffer = 'C';
    if (i == 8)
        buffer = 'D';
    if (i == 10)
        buffer = 'E';
    if (i == 12)
        buffer = 'F';
    if (i == 14)
        buffer = 'G';
    if (i == 16)
        buffer = 'H';
    return (buffer);
}

void sig_handler_win(int signal, siginfo_t *sig, void *test)
{
    (void)sig;
    (void)test;
    static int i = 0;

    if (signal == 12) {
        i = 1;
        global = i;
    }
    if (signal == 10) {
        i = 2;
        global = i;
    }
}

void cond(char buffer, game_t *game, char *str, char lt)
{
    print_values(buffer, game->user.crypt_sec, str);
    game->map.map2[game->user.crypt_sec + 1][game->user.crypt] = lt;
}

void who_kill_who(game_t *game)
{
    int sign = 0;
    char buffer = 0;
    struct sigaction signal;

    signal.sa_sigaction = &sig_handler_win;
    signal.sa_flags = SA_SIGINFO;
    sigaction(10, &signal, NULL);
    signal.sa_sigaction = &sig_handler_win;
    signal.sa_flags = SA_SIGINFO;
    sigaction(12, &signal, NULL);
    while (global == 0) {
        pause();
        sign = global;
    }
    buffer = find_letter(buffer, game->user.crypt);
    if (sign == 1)
        cond(buffer, game, "hit", 'x');
    else if (sign == 2)
        cond(buffer, game, "missed", 'o');
    global = 0;
}