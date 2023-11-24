#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#include "http.h"
#include "../config/config.h"

static void date(void)
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    // Obtenez l'heure actuelle
    time(&rawtime);
    timeinfo = gmtime(&rawtime); // Utilisez gmtime pour obtenir le temps UTC

    // Formattez la date selon le format spécifié
    strftime(buffer, sizeof(buffer), "Date: %a, %d %b %Y %H:%M:%S GMT", timeinfo);

    // Affichez le résultat
    printf("%s\n", buffer);
}

int main(void)
{
    date();
    return 0;
}

/*struct http_response *rules(struct http_request *request)
{
    struct http_response *res = malloc(sizeof(struct http_response));
    struct header *date = malloc(sizeof(struct header));
    date->type = "Date:";
    date->data = 
    res->header = request->headers;
}

void check_method(char *method, struct http_response *response)
{
    //405 Method Not Allowed: Raised when a method not supported/allowed by the server is used in a request.
    // check for method -> only GET and HEAD are allowed
    if (strcmp("GET", method) != 0 && strcmp("HEAD", method) != 0)
    {
        response->status_code = "405";
        response->reason_phrase = "Method Not Allowed";
    }
}

void check_version(char *version, struct http_response *response)
{
    //505 HTTP Version Not Supported: Raised when an HTTP version is other than 1.1.
    if (strcmp("HTTP/1.1", version) != 0)
    {
        response->status_code = "505";
        response->reason_phrase = "Version Not Supported";
    }
}

static int check_host(char *data, struct config *config)
{
    struct server_config *server = config->servers;
    if (strchr(data, ' ') == NULL) // server_name or ip
    {
        for (size_t i = 0; i < config->nb_servers; i++)
        {
            if (strcmp((server[i]).server_name->data, data) == 0 || strcmp((server[i]).ip, data) == 0)
            {
                return 1;
            }       
        }
    }
    else
    {
        char *my_ip= malloc(strlen(data) + 1);
        char *my_port= malloc(strlen(data) + 1);
        char *token = strtok(data, " ");
        strcpy(my_ip, token);
        token = strtok(NULL, " ");
        strcpy(my_port, token);
        for (size_t i = 0; i < config->nb_servers; i++)
        {
            if (strcmp((server[i]).port, my_port) == 0 && strcmp((server[i]).ip, my_ip) == 0)
            {
                free(my_ip);
                free(my_port);
                return 1;
            }       
        }
        free(my_ip);
        free(my_port);
    }
    return 0;
}

static int check_content_length(char *data, struct config *config)
{
    //TODO
    return 0;
}

int check_headers(struct header *headers, struct config *config) // 1 is ok
{
    // used in check_valid_request
    // check if the headers are correct: host & content-length, the rest we don't care
    int is_host = 0;
    struct header *h_cpy = headers;
    while (h_cpy != NULL)
    {
        if (h_cpy->type == NULL || h_cpy->data == NULL)
        {
            return 0;
        }
        if (strcmp(h_cpy->type, "Host:") == 0)
        {
            if (check_host(h_cpy->data, config) == 1)//if valid
            {
                is_host++;
            }
        }
        else if (strcmp(h_cpy->type, "Content-Length:") == 0)
        {
            if (check_content_length(h_cpy->data, config) == 0)
            {
                return 0;
            }
        }
        h_cpy = h_cpy->next;
    }
    if (is_host != 1)
    {
        return 0;
    }
    return 1;
}

void check_valid_request(struct http_request *request, struct http_response *response)
{
    //400 Bad Request if the request is malformed:
    // - Invalid syntax in the client’s request.
    // -Malformed requests using CRLF at random positions.
}

void check_forbidden(char *ressource, struct http_response *response)
{
    // 403 Forbidden: Raised when a client tries to access a resource it does not have permission to.
}

void check_found(char *ressource, struct http_response *response)
{
    // 404 Not Found: Raised when a client tries to access a resource that does not exist.
}

void do_status_line(struct http_request *request, struct http_response *response)
{
    //TODO
}*/