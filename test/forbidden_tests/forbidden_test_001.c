#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/http/http.h"

Test(check_forbidden, access_denied)
{
    struct http_response *r = malloc(sizeof(struct http_response));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;

    char *ressource = "test_files/root/access_forbidden.txt";
    char *root = "root";

    check_forbidden(ressource, root, r);

    char *expected_status = "403";
    char *expected_reason = "Forbidden";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

Test(check_forbidden, access_ok) 
{
    struct http_response *r = malloc(sizeof(struct http_response));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;

    char *ressource = "test_files/root/access_ok.txt";
    char *root = "root";
    check_forbidden(ressource, root, r);

    char *expected_status = "200";
    char *expected_reason = "OK";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}