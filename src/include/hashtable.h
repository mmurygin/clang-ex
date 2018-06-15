#ifndef HASHTABLE_H
#define HASHTABLE_H

#define IN 1
#define OUT 0

struct nlist
{
    struct hash_node * next;
    const char * key;
    const char * value;
};

short has_key(const char * key);
void add_key(const char *key, const char *value);
char * get_key(const char * key);

#endif // HASHTABLE_H
