#include <criterion/criterion.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int split (const char *txt, char delim, char ***tokens)
{
    int *tklen, *t, count = 1;
    char **arr, *p = (char *) txt;

    while (*p != '\0') if (*p++ == delim) count += 1;
    t = tklen = calloc (count, sizeof (int));
    for (p = (char *) txt; *p != '\0'; p++) *p == delim ? *t++ : (*t)++;
    *tokens = arr = malloc (count * sizeof (char *));
    t = tklen;
    p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
    while (*txt != '\0')
    {
        if (*txt == delim)
        {
            p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
            txt++;
        }
        else *p++ = *txt++;
    }
    free (tklen);
    return count;
}


Test(tmpfunction, WIP)
{

    char **tokens;
    int count, i;
    const char *str = "JANasFEB,,MAR,,APR,,MAY,,JUN,,JUL,,AUG,,SEP,,OCT,,NOV,,DEC";

    count = split (str, 'as', &tokens);
    for (i = 0; i < count; i++) printf ("%s\n", tokens[i]);

    /* freeing tokens */
    for (i = 0; i < count; i++) free (tokens[i]);
    free (tokens);
}
