#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "http.h"

static char *tokenize(char *input, char *delimiter) // size_t position
{
    char *string;
    if (input != NULL)
        string = input;
    else
        return NULL;
    char *end = strstr(string, delimiter);
    if (end == NULL) 
    {
        char *temp = string;
        string = NULL;
        return temp;
    }
    char *temp = string;
    *end = '\0';
    string = end + strlen(delimiter);
    return temp;
}

char *get_piece(char *str, char *separator, size_t position)
{
    char *token = tokenize(str, separator);
    size_t current_position = 1;
    while (token != NULL && current_position < position) 
    {
        token = tokenize(NULL, separator);
        current_position++;
    }
    return token;
}

char *get_first_line_from_http_message(char *http_message)
{
    //char *tmp = malloc(strlen(http_message) + 1);
    //strncpy(tmp, http_message, strlen(http_message));
    return get_piece(http_message, "\r\n", 1);
}


struct header *get_headers_http_message(char *http_message)
{
    struct header *res = malloc(sizeof(struct header));
    struct header *res_cpy = res;

    char *tmp = malloc(strlen(http_message) + 1);
    strncpy(tmp, http_message, strlen(http_message));
    size_t i = 2;
    while (1)//if une ligne vide
    {
        struct header *n = malloc(sizeof(struct header));
        char *line = get_piece(tmp, "\r\n", 2);
        if (strlen(line) < 2 || strcmp(line, "\r\n") == 0)
        {
            free(n);
            break;
        }
        res_cpy->type = get_piece(line, " ", 1);
        res_cpy->data = get_piece(line, " ", 2);
        res_cpy->next = n;
        res_cpy = res->next;
        i++;
    }
    res_cpy->next = NULL;
    return res;
}

