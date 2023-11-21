#define _GNU_SOURCE
#define _PSIX_C_SOURCE 200809L
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <limits.h>
#include "server.h"
#include "../config/config.h"

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    int server_socket = create_and_bind(argv[1], argv[2]);
    if (server_socket == -1)
    {
        fprintf(stderr, "Create and bind failed: %s", strerror(errno));
        return 1;
    }

    start_server(server_socket);
    
    close(server_socket);
    return 0;
}


