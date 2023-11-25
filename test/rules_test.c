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

Test(check_forbidden, access_denied) 
{
    struct http_response *r = malloc(sizeof(struct http_request));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;

    char *ressource = "test_files/root/access_forbidden.txt";

    check_forbidden(ressource, r);

    char *expected_status = "403";
    char *expected_reason = "Forbidden";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

Test(check_forbidden, access_ok) 
{
    struct http_response *r = malloc(sizeof(struct http_request));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;

    char *ressource = "test_files/root/access_ok.txt";

    check_forbidden(ressource, r);

    char *expected_status = "200";
    char *expected_reason = "OK";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

Test(check_found, not_exist) 
{
    struct http_response *r = malloc(sizeof(struct http_request));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;

    char *ressource = "test_files/root/invisible.txt";

    check_found(ressource, r);

    char *expected_status = "404";
    char *expected_reason = "Not Found";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

void check_found(char *ressource, struct http_response *response)
{
    // 404 Not Found: Raised when a client tries to access a resource that does not exist.
}