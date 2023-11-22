#include <criterion/criterion.h>
#include "../src/server/httpcommand.h"



Test(httpcommand, parse_command) 
{
    // parse should handle http request
    char http_message[] = "GETSP/hello.txtSPHTTP/1.1CRLFUser-Agent:SPcurl/7.64.1CRLFCRLF";
    struct httprequest *req = parse(http_message);

    char *expected = "GET";
    char *actual = req->command;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}

Test(httpcommand, parse_argument) 
{
    // parse should handle http request
    char http_message[] = "GETSP/hello.txtSPHTTP/1.1CRLFUser-Agent:SPcurl/7.64.1CRLFCRLF";
    struct httprequest *req = parse(http_message);

    char *expected = "/hello.txt";
    char *actual = req->argument;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}


Test(httpcommand, parse_version) 
{
    // parse should handle http request
    char http_message[] = "GETSP/hello.txtSPHTTP/1.1SPCRLFUser-Agent:SPcurl/7.64.1CRLFCRLF";
    struct httprequest *req = parse(http_message);

    char *expected = "HTTP/1.1";
    char *actual = req->version;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}



