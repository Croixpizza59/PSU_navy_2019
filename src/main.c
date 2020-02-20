/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <sys/types.h> 
#include "proto.h"

void signal_handler(int signo, int signo_sec)
{
    pid_t pid = getpid();
    my_putstr("enemy connected\n");
    kill(pid, SIGUSR2);
}

void signal_handler_usr2(int signo, int signo_sec)
{
    my_putstr("successfully connected");
}

int main(int ac, char **av)
{
    pid_t pid;
    struct sigaction s = {0};
    int signo = 10;
    int signo_sec = 12;

    if (ac == 1) {
        pid = getpid();
        printf("my_pid:\t%d\n", pid);
        my_putstr("waiting for enemy connection...\n\n");
        s.sa_handler = signal_handler;
        sigaction(signo, &s, NULL);
        //sigaction(signo_sec, &s, NULL);
        while (1)
          sleep(2);
    }
    else if (ac == 2) {
        printf("my_pid:\t%d\n", getpid());
        pid = to_number(av[1]);
        kill(pid, SIGUSR1); //on envoi le signal
        s.sa_handler = signal_handler_usr2;
        sigaction(signo_sec, &s, NULL);
        while (1)
          sleep(2);
    }
    return (0);
}


/* 
int GLOB = 0;

static void signal_handler(int signo, int signo_sec)
{
  static int var1 = 0;

  printf("Received: signal %d\n", signo);
  printf("Received: signal %d\n", signo_sec);
  if (signo == 10)
    GLOB += 1;
  else
    var1 += 1;
  printf(" usr1 = %d", GLOB);
  printf("usr2 = %d", var1);
} 
 
int main(int argc, char**argv) 
{
    struct sigaction s = {0};
    int signo = 10;
    int signo_sec = 12;

    s.sa_handler = signal_handler;
    sigaction(signo, &s, NULL);
    sigaction(signo_sec, &s, NULL);
    printf("My PID is %d\n", getpid());
    while(1)
        sleep(1);
    return (0);
} 
*/