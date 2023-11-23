#include <criterion/criterion.h>
#include "../src/http/httpcommand.h"



Test(httpcommand, parse_command) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\n";
    struct httprequest *req = parse(http_message);

    char *expected = "GET";
    char *actual = req->command;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}

Test(httpcommand, parse_argument) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\n";
    struct httprequest *req = parse(http_message);

    char *expected = "/hello.txt";
    char *actual = req->path;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}


Test(httpcommand, parse_version) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\n";
    struct httprequest *req = parse(http_message);

    char *expected = "HTTP/1.1";
    char *actual = req->version;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}



Test(httpcommand, parse_headers) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\nHost: www.example.com\r\nAccept-Language: en, mi\r\n";
    struct httprequest *req = parse(http_message);

    char *expected = "User-Agent: curl/7.64.1\r\nHost: www.example.com\r\nAccept-Language: en, mi";
    char *actual = req->headers;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}



