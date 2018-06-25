#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/hashtable.h"

#define HASH_TABLE_SIZE 100

short _has_key(const struct nlist *nlist, const char *key);
void _set_key(struct nlist *nlist, const char *key, const char *value);
char *_get_value(struct nlist *nlist, const char *key);

static struct nlist *hashtable[HASH_TABLE_SIZE] = {};

unsigned _get_hash(const char * key)
{
    unsigned hashval;

    for (hashval = 0; *key != '\0'; key++)
    {
        hashval = *key + 31 * hashval;
    }

    return hashval % HASH_TABLE_SIZE;
}

short _has_key(const struct nlist *nlist, const char * key)
{
    if (nlist == NULL)
    {
        return OUT;
    }

    if (strcmp(nlist->key, key) == 0)
    {
        return IN;
    }

    return _has_key(nlist->next, key);
}

short has_key(const char *key)
{
    unsigned hash = _get_hash(key);

    return _has_key(hashtable[hash], key);
}

char *_get_value(struct nlist *nlist, const char *key)
{
    if (!nlist)
    {
        return NULL;
    }

    if (strcmp(nlist->key, key) == 0)
    {
        return nlist->value;
    }

    return _get_value(nlist->next, key);
}

char *get_value(const char *key)
{
    unsigned hash = _get_hash(key);

    return _get_value(hashtable[hash], key);
}

struct nlist *_allocnlist(const char *key, const char *value)
{
    struct nlist *nlist = malloc(sizeof(struct nlist));
    nlist->next = NULL;
    nlist->key = strdup(key);
    nlist->value = strdup(value);

    return nlist;
}

void _set_key(struct nlist *nlist, const char *key, const char *value)
{
    if (nlist->next)
    {
        _set_key(nlist->next, key, value);
    }
    else
    {
        nlist->next = _allocnlist(key, value);
    }
}

void set_key(const char *key, const char *value)
{
    unsigned hash = _get_hash(key);
    if (!hashtable[hash])
    {
        hashtable[hash] = _allocnlist(key, value);
        return;
    }

    char * hashed_value = _get_value(hashtable[hash], key);
    if (hashed_value)
    {
        strcpy(hashed_value, value);
        return;
    }

    _set_key(hashtable[hash], key, value);
}
