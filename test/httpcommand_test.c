#include <criterion/criterion.h>
#include "../src/server/httpcommand.h"

Test(httpcommand, parse_some) 
{
    // get_piece function should return desired position of string
    char *http_message = "GETSP/hello.txtSPHTTP/1.1CRLFUser-Agent:SPcurl/7.64.1CRLFCRLF";
    char *expected = "GET";
    //struct httprequest *req = parse(http_message);
    char *actual = "req->command";
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}

