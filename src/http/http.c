#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "http.h"

char *get_piece(char *str, char *separator, size_t position)
{
    char *str_copy = strdup(str);
    if (str_copy == NULL) 
    {
        perror("Memory allocation error");
        return NULL;
    }
    size_t current_position = 1;
    char *token = strtok(str_copy, separator);
    while (token != NULL && current_position < position) 
    {
        token = strtok(NULL, separator);
        current_position++;
    }
    return token;
}
/*char *get_piece(char *str, char *separator, size_t position) {
    size_t separator_len = strlen(separator);
    size_t str_len = strlen(str);
    size_t current_position = 1;
    size_t start_word = 0;
    size_t end_word = 0;

    for (size_t i = 0; i < str_len; i++) {
        size_t i_separator = 0;

        if (str[i] == separator[i_separator]) {
            start_word = i;

            while (i_separator < separator_len) {
                if (str[i] == separator[i_separator]) {
                    i++;
                    i_separator++;
                } else {
                    start_word = i - i_separator;
                    i_separator = 0;
                    break;
                }
            }

            if (i_separator == separator_len) {
                end_word = i;
                i += separator_len;

                while (i < str_len && strncmp(str + i, separator, separator_len) != 0) {
                    i++;
                }

                current_position++;

                if (current_position == position) {
                    size_t token_length = i - end_word;
                    char *result = malloc(token_length + 1);
                    if (result == NULL) {
                        perror("Memory allocation error");
                        return NULL;
                    }

                    strncpy(result, str + start_word, token_length);
                    result[token_length] = '\0';

                    return result;
                }
            }
        }
    }

    return NULL;
}
*/

char *get_first_line_from_http_message(char *http_message)
{
    return get_piece(http_message, "CRLF", 1);
}

/*
int main() 
{
    // Example string, separator, and position
    char input_string[] = "apple,,orange,,banana,,grape";
    char separator[] = ",,";
    size_t position_to_get = 3;

    // Call the get_piece function
    char *result = get_piece(input_string, separator, position_to_get);

    // Check if result is not NULL before using it
    if (result != NULL) {
        printf("Element at position %zu: %s\n", position_to_get, result);
    } else {
        printf("Element at position %zu not found\n", position_to_get);
    }

    return 0;
}
*/