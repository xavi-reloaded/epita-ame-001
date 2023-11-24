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



Test(httpcommand, parse_headers) 
{
    char http_message[] = "GET /hello.txt HTTP/1.1\r\nUser-Agent: curl/7.64.1\r\nHost: www.example.com\r\nAccept-Language: en, mi\r\n\r\n";
    struct http_request *req = parse(http_message);

    struct header *expected = malloc(sizeof(struct header));
    struct header *h2 = malloc(sizeof(struct header));
    struct header *h3 = malloc(sizeof(struct header));
    expected->type = "User-Agent:";
    expected->data = "curl/7.64.1";
    expected->next = h2;
    h2->type = "Host:";
    h2->data = "www.example.com";
    h2->next = h3;
    h3->type = "Accept-Language:";
    h3->data = "en, mi";
    h3->next = NULL;

    struct header *actual = req->headers;

    cr_assert(strcmp(actual->type, expected->type) == 0, "Type mismatch");
    cr_assert(strcmp(actual->data, expected->data) == 0, "Data mismatch");

    actual = actual->next;
    expected = expected->next;

    cr_assert(strcmp(actual->type, expected->type) == 0, "Type mismatch");
    cr_assert(strcmp(actual->data, expected->data) == 0, "Data mismatch");

    actual = actual->next;
    expected = expected->next;

    cr_assert(actual == NULL && expected == NULL, "List length mismatch");
}



