#include <criterion/criterion.h>
#include "../src/http/http.h"
/*
Test(get_piece, simple) 
{
    // get_piece function should return desired position of string
    char *str = "hello^^pepito^^you^^are^^nice";
    const char *separator = "^^";
    size_t position = 3;
    char *expected = "you";

    char *actual = get_piece(str, separator, position);

    cr_assert(actual != NULL, "Actual value is NULL");
    cr_assert(expected != NULL, "Expected value is NULL");
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}
*/


Test(get_piece, one) 
{
    // get_piece function should return desired position of string
    char *str = "hello^pepito^you^are^nice";
    const char *separator = "^";
    size_t position = 3;
    char *expected = "you";

    char *actual = get_piece(str, separator, position);
    //cr_assert_eq(actual, expected);
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}



/*
Test(get_first_line_from_http_message, simple) 
{
    // get_first_line function should return desired position of string
    char *http_message = "GETSP/hello.txtSPHTTP/1.1CRLFUser-Agent:SPcurl/7.64.1CRLFCRLF";
    char *expected = "GETSP/hello.txtSPHTTP/1.1";
    char *actual = get_first_line_from_http_message(http_message);

    cr_assert(actual != NULL, "Actual value is NULL");
    cr_assert(expected != NULL, "Expected value is NULL");
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}*/