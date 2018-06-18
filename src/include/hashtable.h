#ifndef HASHTABLE_H
#define HASHTABLE_H

#define IN 1
#define OUT 0

struct nlist
{
    struct nlist * next;
    char * key;
    char * value;
};

void set_key(const char *key, const char *value);
char * get_value(const char * key);

#endif // HASHTABLE_H
