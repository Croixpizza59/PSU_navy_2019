/*
** EPITECH PROJECT, 2020
** navy
** File description:
** hit_or_miss
*/

#include "proto.h"

static void print_values(char letter, int nb, char *str)
{
    my_putchar(letter);
    my_putstr(show_number(nb));
    my_putstr(": ");
    my_putstr(str);
    my_putstr("\n\n");
}

static char find_letter(char buffer, int i)
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

static void sig_handler_win(int signal, siginfo_t *sig, void *stream)
{
    (void)sig;
    (void)stream;

    if (signal == 12) {
        global = 1;
    } else if (signal == 10) {
        global = 2;
    }
}

static void cond(char buffer, navy_t *navy, char *str, char lt)
{
    print_values(buffer, navy->coord.crypt_sec, str);
    navy->map.map_dup[navy->coord.crypt_sec + 1][navy->coord.crypt] = lt;
}

void hit_or_miss(navy_t *navy)
{
    int sign = 0;
    char buffer = 0;
    struct sigaction signal;

    signal.sa_sigaction = &sig_handler_win;
    signal.sa_flags = SA_SIGINFO;
    sigaction(12, &signal, NULL);
    sigaction(10, &signal, NULL);
    while (global == 0) {
        pause();
        sign = global;
    }
    buffer = find_letter(buffer, navy->coord.crypt);
    if (sign == 1)
        cond(buffer, navy, "hit", 'x');
    else if (sign == 2)
        cond(buffer, navy, "missed", 'o');
    global = 0;
}