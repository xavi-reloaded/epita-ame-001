#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "http.h"

char *tokenize(char *input, char *delimiter, size_t position) {
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
    char *token = tokenize(str, separator, position);
    size_t current_position = 1;
    while (token != NULL && current_position < position) {
        token = tokenize(NULL, separator, position);
        current_position++;
    }
    return token;
}

char *get_first_line_from_http_message(char *http_message)
{
    char *tmp = malloc(strlen(http_message) + 1);
    strncpy(tmp, http_message, strlen(http_message));
    return get_piece(tmp, "\r\n", 1);
}


char *get_headers_http_message(char *http_message)
{
    char *tmp = malloc(strlen(http_message) + 1);
    strncpy(tmp, http_message, strlen(http_message));
    char *token1 = get_piece(tmp, "\r\n", 2);
    
    char *tmp2 = malloc(strlen(http_message) + 1);
    strncpy(tmp2, http_message, strlen(http_message));
    char *token2 = get_piece(tmp2, "\r\n", 3);

    char *tmp3 = malloc(strlen(http_message) + 1);
    strncpy(tmp3, http_message, strlen(http_message));
    char *token3 = get_piece(tmp3, "\r\n", 4);

    char *result = malloc(strlen(http_message) + 100);

    strcpy(result, token1);  // Copy str1 into result
    strcat(result, "\r\n");
    strcat(result, token2);
    return result;
}

