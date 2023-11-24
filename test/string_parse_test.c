#include <criterion/criterion.h>
#include "../src/http/http.h"

Test(get_piece, separator_SP) 
{
    // get_piece function should return desired position of string
    char str[] = "helloSPpepitoSPyouSPareSPnice";
    char separator[] = "SP";
    size_t position = 5;
    char *expected = "nice";

    char *actual = get_piece(str, separator, position);

    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}



Test(get_piece, one_length_separator) 
{
    // get_piece function should return desired position of string
    char str[] = "apple,orange,banana,grape";
    char separator[] = ",";
    size_t position = 2;
    char *expected = "orange";

    char *actual = get_piece(str, separator, position);
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}


Test(get_first_line_from_http_message, when_string_contains_part_of_sedparator) 
{
    // get_first_line function should return desired position of string
    char str[] = "GET /hello.txt HTTPS/1.1\r\nwekeinendel";
    char separator[] = "\r\n";
    size_t position = 1;
    char *expected = "GET /hello.txt HTTPS/1.1";

    char *actual = get_piece(str, separator, position);

    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}

Test(get_first_line_from_http_message, simple) 
{
    // get_first_line function should return desired position of string
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent:SPcurl/7.64.1\r\n\r\n";
    char *expected = "GET /hello.txt HTTP/1.1";
    char *actual = get_first_line_from_http_message(http_message);

    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}


