#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "../src/http/http.h"
#include "../src/config/config.h"
#include "../src/utils/string/string.h"

Test(check_headers, ok_servername) 
{
    struct header *h = malloc(sizeof(struct header));
    h->type = "Host:";
    h->data = "sever_name";
    h->next = NULL;

    struct server_config *s = malloc(sizeof(struct server_config));
    const char *name = "server_name";
    s->server_name = string_create(name, strlen(name));
    s->port = "8000";
    s->ip = "127.0.0.1";
    s->root_dir = NULL;
    s->default_file = NULL;

    struct config *c = malloc(sizeof(struct config));
    c->log = NULL;
    c->log_file = NULL;
    c->pid_file = NULL;
    c->nb_servers = 1;
    c->servers = s;

    char *body = "bodybodybody";

    int actual = check_headers(h, body, c);
    int expected = 1; // ok
    cr_assert_eq(actual, expected);
}

Test(check_headers, ok_ip) 
{
    struct header *h = malloc(sizeof(struct header));
    h->type = "Host:";
    h->data = "127.0.0.1";
    h->next = NULL;

    struct server_config *s = malloc(sizeof(struct server_config));
    const char *name = "server_name";
    s->server_name = string_create(name, strlen(name));
    s->port = "8000";
    s->ip = "127.0.0.1";
    s->root_dir = NULL;
    s->default_file = NULL;

    struct config *c = malloc(sizeof(struct config));
    c->log = NULL;
    c->log_file = NULL;
    c->pid_file = NULL;
    c->nb_servers = 1;
    c->servers = s;

    char *body = "bodybodybody";

    int actual = check_headers(h, body, c);
    int expected = 1; // ok
    cr_assert_eq(actual, expected);
}

Test(check_headers, ok_ip_port) 
{
    struct header *h = malloc(sizeof(struct header));
    h->type = "Host:";
    h->data = "127.0.0.1 8000";
    h->next = NULL;

    struct server_config *s = malloc(sizeof(struct server_config));
    const char *name = "server_name";
    s->server_name = string_create(name, strlen(name));
    s->port = "8000";
    s->ip = "127.0.0.1";
    s->root_dir = NULL;
    s->default_file = NULL;

    struct config *c = malloc(sizeof(struct config));
    c->log = NULL;
    c->log_file = NULL;
    c->pid_file = NULL;
    c->nb_servers = 1;
    c->servers = s;

    char *body = "bodybodybody";

    int actual = check_headers(h, body, c);
    int expected = 1; // ok
    cr_assert_eq(actual, expected);
}

Test(check_headers, no_host) 
{
    struct header *h = malloc(sizeof(struct header));
    h->type = "Mierder:";
    h->data = "127.0.0.1 8000";
    h->next = NULL;

    struct server_config *s = malloc(sizeof(struct server_config));
    const char *name = "server_name";
    s->server_name = string_create(name, strlen(name));
    s->port = "8000";
    s->ip = "127.0.0.1";
    s->root_dir = NULL;
    s->default_file = NULL;

    struct config *c = malloc(sizeof(struct config));
    c->log = NULL;
    c->log_file = NULL;
    c->pid_file = NULL;
    c->nb_servers = 1;
    c->servers = s;

    char *body = "bodybodybody";

    int actual = check_headers(h, body, c);
    int expected = 0; // err
    cr_assert_eq(actual, expected);
}

Test(check_headers, valid_length)
{
    struct header *h1 = malloc(sizeof(struct header));
    h1->type = "Content-Length:";
    h1->data = "13"; //strlen(body)
    h1->next = NULL;

    struct header *h = malloc(sizeof(struct header));
    h->type = "Host:";
    h->data = "server_name";
    h->next = h1;

    struct server_config *s = malloc(sizeof(struct server_config));
    const char *name = "server_name";
    s->server_name = string_create(name, strlen(name));
    s->port = "8000";
    s->ip = "127.0.0.1";
    s->root_dir = NULL;
    s->default_file = NULL;

    struct config *c = malloc(sizeof(struct config));
    c->log = NULL;
    c->log_file = NULL;
    c->pid_file = NULL;
    c->nb_servers = 1;
    c->servers = s;

    char *body = "bodybodybody";

    int actual = check_headers(h, body, c);
    int expected = 1; // ok
    cr_assert_eq(actual, expected);
}

Test(check_headers, null_length)
{
    struct header *h1 = malloc(sizeof(struct header));
    h1->type = "Content-Length:";
    h1->data = "0"; //strlen(body)
    h1->next = NULL;

    struct header *h = malloc(sizeof(struct header));
    h->type = "Host:";
    h->data = "server_name";
    h->next = h1;

    struct server_config *s = malloc(sizeof(struct server_config));
    const char *name = "server_name";
    s->server_name = string_create(name, strlen(name));
    s->port = "8000";
    s->ip = "127.0.0.1";
    s->root_dir = NULL;
    s->default_file = NULL;

    struct config *c = malloc(sizeof(struct config));
    c->log = NULL;
    c->log_file = NULL;
    c->pid_file = NULL;
    c->nb_servers = 1;
    c->servers = s;

    char *body = NULL;

    int actual = check_headers(h, body, c);
    int expected = 1; // ok
    cr_assert_eq(actual, expected);
}

Test(check_headers, invalid_length)
{
    struct header *h1 = malloc(sizeof(struct header));
    h1->type = "Content-Length:";
    h1->data = "10"; //strlen(body)
    h1->next = NULL;

    struct header *h = malloc(sizeof(struct header));
    h->type = "Host:";
    h->data = "server_name";
    h->next = h1;

    struct server_config *s = malloc(sizeof(struct server_config));
    const char *name = "server_name";
    s->server_name = string_create(name, strlen(name));
    s->port = "8000";
    s->ip = "127.0.0.1";
    s->root_dir = NULL;
    s->default_file = NULL;

    struct config *c = malloc(sizeof(struct config));
    c->log = NULL;
    c->log_file = NULL;
    c->pid_file = NULL;
    c->nb_servers = 1;
    c->servers = s;

    char *body = "bodybodybody";

    int actual = check_headers(h, body, c);
    int expected = 0; // ok
    cr_assert_eq(actual, expected);
}

Test(valid_request, valid)
{
    struct header *h = malloc(sizeof(struct header));
    h->type = "Host:";
    h->data = "server_name";
    h->next = NULL;

    struct http_request *req = malloc(sizeof(struct http_request));
    req->command = "GET";
    req->path = "test_files/root/access_ok.txt";
    req->version = "HTTP/1.1";
    req->headers = h;

    struct http_response *r = malloc(sizeof(struct http_response));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;

    struct server_config *s = malloc(sizeof(struct server_config));
    const char *name = "server_name";
    s->server_name = string_create(name, strlen(name));
    s->port = "8000";
    s->ip = "127.0.0.1";
    s->root_dir = NULL;
    s->default_file = NULL;

    struct config *c = malloc(sizeof(struct config));
    c->log = NULL;
    c->log_file = NULL;
    c->pid_file = NULL;
    c->nb_servers = 1;
    c->servers = s;

    check_valid_request(req, r, c);

    char *expected_status = "200";
    char *expected_reason = "OK";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

Test(valid_request, not_valid_no_host)
{
    struct header *h = malloc(sizeof(struct header));
    h->type = "Mierder:";
    h->data = "server_name";
    h->next = h;

    struct http_request *req = malloc(sizeof(struct http_request));
    req->command = "GET";
    req->path = "test_files/root/access_ok.txt";
    req->version = "HTTP/1.1";
    req->headers = h;

    struct http_response *r = malloc(sizeof(struct http_response));
    r->status_code = "200";
    r->reason_phrase = "OK";
    r->header = NULL;
    r->http_version = NULL;
    r->body = NULL;

    struct server_config *s = malloc(sizeof(struct server_config));
    const char *name = "server_name";
    s->server_name = string_create(name, strlen(name));
    s->port = "8000";
    s->ip = "127.0.0.1";
    s->root_dir = NULL;
    s->default_file = NULL;

    struct config *c = malloc(sizeof(struct config));
    c->log = NULL;
    c->log_file = NULL;
    c->pid_file = NULL;
    c->nb_servers = 1;
    c->servers = s;

    check_valid_request(req, r, c);

    char *expected_status = "400";
    char *expected_reason = "Bad Request";

    struct http_response *actual = r;
    cr_assert(strcmp(actual->status_code, expected_status) == 0, "Actual: %s, Expected: %s", actual->status_code, expected_status);
    cr_assert(strcmp(actual->reason_phrase, expected_reason) == 0, "Actual: %s, Expected: %s", actual->reason_phrase, expected_reason);
}

//Not exaustive