#include <criterion/criterion.h>
#include "../src/http/http.h"


Test(get_piece, when_spaces) 
{
    // get_first_line function should return desired position of string
    char str[] = "GET /hello.txt HTTP/1.1";
    char separator[] = " ";
    size_t position = 3;
    char *expected = "HTTP/1.1";

    char *actual = get_piece(str, separator, position);

    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}


Test(get_piece, when_end_carriage_firstline) 
{
    // get_first_line function should return desired position of string
    char str[] = "GET /hello.txt HTTP/1.1\r\n";
    char separator[] = "\r\n";
    size_t position = 1;
    char *expected = "GET /hello.txt HTTP/1.1";

    char *actual = get_piece(str, separator, position);

    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}



