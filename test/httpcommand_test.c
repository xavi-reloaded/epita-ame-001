#include <criterion/criterion.h>
#include "../src/http/http.h"



Test(httpcommand, parse_command) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\n";
    struct http_request *req = parse(http_message);

    char *expected = "GET";
    char *actual = req->command;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}

Test(httpcommand, parse_argument) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\n";
    struct http_request *req = parse(http_message);

    char *expected = "/hello.txt";
    char *actual = req->path;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}


Test(httpcommand, parse_version) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\n";
    struct http_request *req = parse(http_message);

    char *expected = "HTTP/1.1";
    char *actual = req->version;
    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}

Test(httpcommand, no_headers) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\n\r\n";
    struct http_request *req = parse(http_message);

    struct header *expected = NULL;
    struct header *actual = req->headers;
    cr_assert_eq(expected, actual);
}

Test(httpcommand, parse_one_header) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\n\r\n";
    struct http_request *req = parse(http_message);

    struct header *expected = malloc(sizeof(struct header));
    expected->type = "User-Agent:";
    expected->data = "curl/7.64.1";
    expected->next = NULL;

    struct header *actual = req->headers;

    cr_assert(strcmp(actual->type, expected->type) == 0, "Actual: %s, Expected: %s", actual, expected);
    cr_assert(strcmp(actual->data, expected->data) == 0, "Actual: %s, Expected: %s", actual, expected);

    actual = actual->next;
    expected = expected->next;

    cr_assert(actual == NULL && expected == NULL, "List length mismatch");
}

Test(httpcommand, parse_two_headers) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\nMierdus: mierdermierder\r\n\r\n";
    struct http_request *req = parse(http_message);

    struct header *actual = req->headers;

    cr_assert(strcmp(actual->type, "User-Agent:") == 0, "Actual: %s, Expected: %s", actual->type, "User-Agent:");
    cr_assert(strcmp(actual->data, "curl/7.64.1") == 0, "Actual: %s, Expected: %s", actual->data, "curl/7.64.1");

    actual = actual->next;

    cr_assert(strcmp(actual->type, "Mierdus:") == 0, "Actual: %s, Expected: %s", actual->type, "Mierdus:");
    cr_assert(strcmp(actual->data, "mierdermierder") == 0, "Actual: %s, Expected: %s", actual->data, "mierdermierder");

    cr_assert(actual == NULL, "List length mismatch");
}


