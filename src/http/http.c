#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "http.h"

char *get_piece(char *str, char *separator, size_t position)
{
    size_t current_position = 1;

    char *token = strtok(str, separator);
    while (token != NULL && current_position < position) 
    {
        token = strtok(NULL, separator);
        current_position++;
    }
    return token;
}

char *get_first_line_from_http_message(char *http_message)
{
    return get_piece(http_message, "CRLF", 1);
}
/*
int main() 
{
    // Example string, separator, and position
    char input_string[] = "apple,orange,banana,grape";
    char separator[] = ",";
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
}*/
