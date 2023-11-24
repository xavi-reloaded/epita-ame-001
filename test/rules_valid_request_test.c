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

    int actual = check_headers(h, c);
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

    int actual = check_headers(h, c);
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

    int actual = check_headers(h, c);
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

    int actual = check_headers(h, c);
    int expected = 0; // err
    cr_assert_eq(actual, expected);
}

/*Test(check_headers, invalid_length) //TODO
{
    struct header *h1 = malloc(sizeof(struct header));
    h1->type = "Content-Length:";
    h1->data = "";//todo
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

    int actual = check_headers(h);
    int expected = 0; // err
    cr_assert_eq(actual, expected);
}*/

//TODO add valid_request test