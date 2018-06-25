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

struct node *get_node_by_word(struct node *root, const char * word);
struct node *add_new_word_to_tree(struct node *root, const char *word);

#endif
