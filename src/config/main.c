#define _GNU_SOURCE

#include "config.h"

#include <fnmatch.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_server_config(struct server_config *server) 
{
    if (server != NULL) {
        printf("Server Name: %s\n", server->server_name ? server->server_name->data : "NULL");
        printf("Port: %s\n", server->port ? server->port : "NULL");
        printf("IP: %s\n", server->ip ? server->ip : "NULL");
        printf("Root Dir: %s\n", server->root_dir ? server->root_dir : "NULL");
        printf("Default File: %s\n", server->default_file ? server->default_file : "NULL");
    }
}


void print_config(struct config *cfg) 
{
    if (cfg != NULL) 
    {
   
        printf("PID File: %s\n", cfg->pid_file ? cfg->pid_file : "NULL");
        printf("Log File: %s\n", cfg->log_file ? cfg->log_file : "NULL");
        printf("Logging: %s\n", cfg->log ? "Enabled" : "Disabled");

        printf("Number of Servers: %zu\n", cfg->nb_servers);
        for (size_t i = 0; i < cfg->nb_servers; ++i) {
            printf("Server %zu:\n", i + 1);
            print_server_config(&cfg->servers[i]);
        }
    }
}

/*
int main()
{
    struct config *cfg = parse_configuration("test.txt");
    if (cfg == NULL)
    {
	    printf("invalid\n");
	    return 0;
    }
    print_config(cfg);
    config_destroy(cfg);
    return 0;
}
*/