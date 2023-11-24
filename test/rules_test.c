#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "../src/http/http.h"

Test(check_method, error) 
{
    struct http_response *r = malloc(sizeof(struct http_request));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;


    check_method("MIERDER", r);

    char *expected_status = "405";
    char *expected_reason = "Method Not Allowed";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

Test(check_method, GET) 
{
    struct http_response *r = malloc(sizeof(struct http_request));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;


    check_method("GET", r);

    char *expected_status = "200";
    char *expected_reason = "OK";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

Test(check_method, HEAD) 
{
    struct http_response *r = malloc(sizeof(struct http_request));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;


    check_method("HEAD", r);

    char *expected_status = "200";
    char *expected_reason = "OK";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

Test(check_version, good) 
{
    struct http_response *r = malloc(sizeof(struct http_request));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;


    check_version("HTTP/1.1", r);

    char *expected_status = "200";
    char *expected_reason = "OK";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

Test(check_version, error) 
{
    struct http_response *r = malloc(sizeof(struct http_request));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;


    check_version("HTTP/3.0", r);

    char *expected_status = "505";
    char *expected_reason = "Version Not Supported";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}
//TODO add tests for check forbidden & check_found