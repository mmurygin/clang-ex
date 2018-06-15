#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/hashtable.h"

#define HASH_TABLE_SIZE 100

short _has_key_in_nlist(const struct nlist *nlist, const char *key);
void _add_value_to_nlist(struct nlist *nlist, const char *key, const char *value);

static struct nlist *hashtable[HASH_TABLE_SIZE] = {};

unsigned _get_hash_value(const char * key)
{
    unsigned hashval;

    for (hashval = 0; *key != '\0'; key++)
    {
        hashval = *key + 31 * hashval;
    }

    return hashval % HASH_TABLE_SIZE;
}

short _has_key_in_nlist(const struct nlist *nlist, const char * key)
{
    if (nlist == NULL)
    {
        return OUT;
    }

    if (strcmp(nlist->key, key) == 0)
    {
        return IN;
    }

    return _has_key_in_nlist(nlist->next, key);
}

short has_key(const char *key)
{
    unsigned hash = _get_hash_value(key);

    return _has_key_in_nlist(hashtable[hash], key);
}

struct nlist *_allocnlist(const char *key, const char *value)
{
    struct nlist *nlist = malloc(sizeof(struct nlist));
    nlist->next = NULL;
    nlist->key = strdup(key);
    nlist->value = strdup(value);

    return nlist;
}

void _add_value_to_nlist(struct nlist *nlist, const char *key, const char *value)
{
    if (nlist->next)
    {
        _add_value_to_nlist(nlist->next, key, value);
    }
    else
    {
        nlist->next = _allocnlist(key, value);
    }
}

void add_key(const char *key, const char *value)
{
    if (has_key(key))
    {
        printf("Error: try to add dublicate key \"%s\"", key);
        return;
    }

    unsigned hash = _get_hash_value(key);

    if (hashtable[hash])
    {
        _add_value_to_nlist(hashtable[hash], key, value);
    }
    else
    {
        hashtable[hash] = _allocnlist(key, value);
    }
}

char * get_key(const char *key)
{

}
