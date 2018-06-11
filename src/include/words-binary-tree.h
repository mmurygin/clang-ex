#ifndef WORDS_BINARY_TREE
#define WORDS_BINARY_TREE

struct word_key
{
    char *word;
    int count;
};

struct node
{
    struct word_key *value;
    struct node *left;
    struct node *right;
};

struct word_key * get_node_by_word(const struct node *root, const char * word);
struct node *add_new_word_to_tree(const struct node *root, const char *word);

#endif
