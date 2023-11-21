#define _GNU_SOURCE
#include "config.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 1024

static void create_server(struct config *config) // to test
{
    config->servers[config->nb_servers - 1].server_name = NULL;
    config->servers[config->nb_servers - 1].port = NULL;
    config->servers[config->nb_servers - 1].ip = NULL;
    config->servers[config->nb_servers - 1].root_dir = NULL;
    config->servers[config->nb_servers - 1].default_file = NULL;
}

static void global(FILE *file, struct config *config)
{
    char line[LINE_MAX];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (line[0] == '\n' || line[0] == '\r') // empty line
            break;
        char *w = strtok(line, " ");
        strtok(NULL, " ");
        if (strcmp(w, "pid_file") == 0)
        {
            w = strtok(NULL, "\n");
            config->pid_file = strdup(w);
        }
        else if (strcmp(w, "log_file") == 0)
        {
            w = strtok(NULL, "\n");
            config->log_file = strdup(w);
        }
        else if (strcmp(w, "log") == 0)
        {
            w = strtok(NULL, "\n");
            if (strcmp(w, "true") == 0)
                config->log = true;
            else
                config->log = false;
        }
    }
}

static void vhosts(FILE *file, struct config *config)
{
    config->nb_servers += 1;
    config->servers = realloc(
        config->servers, sizeof(struct server_config) * config->nb_servers);
    create_server(config);
    char line[LINE_MAX];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (line[0] == '\n' || line[0] == '\r') // empty line
            break;
        char *w = strtok(line, " ");
        strtok(NULL, " ");
        if (strcmp(w, "server_name") == 0)
        {
            w = strtok(NULL, "\n");
            struct string *str = string_create(w, strlen(w));
            config->servers[config->nb_servers - 1].server_name = str;
        }
        else if (strcmp(w, "port") == 0)
        {
            w = strtok(NULL, "\n");
            config->servers[config->nb_servers - 1].port = strdup(w);
        }
        else if (strcmp(w, "ip") == 0)
        {
            w = strtok(NULL, "\n");
            config->servers[config->nb_servers - 1].ip = strdup(w);
        }
        else if (strcmp(w, "root_dir") == 0)
        {
            w = strtok(NULL, "\n");
            config->servers[config->nb_servers - 1].root_dir = strdup(w);
        }
        else if (strcmp(w, "default_file") == 0)
        {
            w = strtok(NULL, "\n");
            config->servers[config->nb_servers - 1].default_file = strdup(w);
        }
    }
}

static void parseur(FILE *file, struct config *config,
                    char *line) // to implement
{
    char *w = strtok(line, "\n");
    if (strcmp(w, "[[vhosts]]") == 0)
    {
        vhosts(file, config);
    }
    else if (strcmp(w, "[global]") == 0)
    {
        global(file, config);
    }
}

static int check_config(struct config *config) // 2 if invalid
{
    if (config->pid_file == NULL)
        return 2;
    if (config->nb_servers == 0)
        return 2;
    for (size_t i = 0; i < config->nb_servers; i++)
    {
        if (config->servers[i].server_name == NULL)
            return 2;
        if (config->servers[i].port == NULL)
            return 2;
        if (config->servers[i].ip == NULL)
            return 2;
        if (config->servers[i].root_dir == NULL)
            return 2;
    }
    return 0;
}

struct config *parse_configuration(const char *path) // to test
{
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        perror("parse_configuration: Error fopen\n");
        return NULL;
    }
    struct config *res = malloc(sizeof(struct config));
    if (res == NULL)
    {
        perror("parse_configuration: Error malloc\n");
        return NULL;
    }
    res->pid_file = NULL;
    res->log_file = NULL;
    res->log = true;
    res->servers = NULL;
    res->nb_servers = 0;
    char line[LINE_MAX];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (line[0] == '\n' || line[0] == '\r') // empty line
            continue;
        parseur(file, res, line);
    }
    fclose(file);
    if (check_config(res) == 2)
    {
        config_destroy(res);
        return NULL;
    }
    return res;
}

static void server_destroy(struct server_config *server)
{
    if (server->server_name != NULL)
        string_destroy(server->server_name);
    if (server->port != NULL)
        free(server->port);
    if (server->ip != NULL)
        free(server->ip);
    if (server->root_dir != NULL)
        free(server->root_dir);
    if (server->default_file != NULL)
        free(server->default_file);
    free(server);
}

void config_destroy(struct config *config)
{
    if (config != NULL)
    {
        if (config->servers != NULL)
            server_destroy(config->servers);
        if (config->pid_file != NULL)
            free(config->pid_file);
        if (config->log_file != NULL)
            free(config->log_file);
        free(config);
    }
}
