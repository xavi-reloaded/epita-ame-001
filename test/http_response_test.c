#include <criterion/criterion.h>
#include <stdlib.h>
#include "../src/http/http.h"

Test(http_response_from_struct_response, valid_struct) 
{
    struct header *h1 = malloc(sizeof(struct header));
    struct header *h2 = malloc(sizeof(struct header));
    h1->type = "Date:";
    h1->data = "12 november 2023";
    h1->next = h2;
    h2->type = "Size:";
    h2->data = "12";
    h2->next = NULL;

    struct http_response *resp = malloc(sizeof(struct http_response));
    resp->http_version = "HTTP/1.1";
    resp->status_code = "200";
    resp->reason_phrase = "OK";
    resp->header = h1;
    resp->body = "bodybodybodybody";
    
    char expected[] = "HTTP/1.1 200 OK\r\nDate: 12 november 2023\r\nSize: 12\r\n\r\nbodybodybodybody";
    char *actual = response_from_struct_response(resp);

    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", actual, expected);
}

