#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "http.h"

static char *tokenize(char *input, char *delimiter)
{
    static char *string;
    if (input != NULL)
        string = input;
    if (string == NULL)
        return string;
    char *end = strstr(string, delimiter);
    if (end == NULL) {
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
    char *tmp = malloc(strlen(http_message) + 1);
    strncpy(tmp, http_message, strlen(http_message));
    return get_piece(tmp, "\r\n", 1);
    free(tmp);
}

void destroy_header(struct header *head) 
{
    while (head != NULL) {
        struct header *temp = head;
        head = head->next;
        free(temp->type);
        free(temp->data);
        free(temp);
    }
}

struct header *get_headers_http_message(char *http_message)
{
    char *message_copy = malloc(strlen(http_message) + 1);
    message_copy = strcpy(message_copy, http_message);
    if (message_copy == NULL) 
    {
        perror("Memory allocation error");
        return NULL;
    }

    struct header *head = NULL;
    struct header *current = NULL;
    size_t i = 2;
    char *line = get_piece(message_copy, "\r\n", i);

    while (line != NULL && strlen(line) > 2) 
    {
        struct header *new_header = malloc(sizeof(struct header));
        if (new_header == NULL) 
        {
            perror("Memory allocation error");
            destroy_header(head);
            free(message_copy);
            return NULL;
        }

        new_header->data = get_piece(line, " ", 2);
        new_header->type = get_piece(line, " ", 1);
        new_header->next = NULL;

        if (head == NULL) 
        {
            head = new_header;
            current = new_header;
        } 
        else 
        {
            current->next = new_header;
            current = new_header;
        }
        i++;
        char *copy = malloc(strlen(http_message) + 1);
        copy = strcpy(copy, http_message);
        if (copy == NULL) 
        {
            perror("Memory allocation error");
            return NULL;
        }
        line = get_piece(copy, "\r\n", i);
        free(copy);
    }

    free(message_copy);
    return head;
}

void destroy_request(struct http_request *request) 
{
    if (request == NULL) {
        return;
    }

    free(request->command);
    free(request->path);
    free(request->version);
    destroy_header(request->headers);
    free(request);
}

void destroy_response(struct http_response *response) 
{
    if (response == NULL) {
        return;
    }

    free(response->http_version);
    free(response->status_code);
    free(response->reason_phrase);
    destroy_header(response->header);
    free(response->body);
    free(response);
}

