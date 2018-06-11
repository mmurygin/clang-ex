#include <stdio.h>
#include <string.h>
#include "include/words-binary-tree.h"

struct word_key *create_word_key(const char * word)
{
    struct word_key *word_key = malloc(sizeof(struct word_key));
    word_key->count = 1;
    word_key->word = word;

    return word_key;
}

struct node *create_new_node(struct word_key * val)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = val;

    return new_node;
}

struct node * add_new_word_to_tree(const struct node *root, const char *word)
{
    struct word_key * word_key = create_word_key(word);
    struct node * node = create_new_node(word_key);

    return add_new_word_to_tree(root, node);
}

struct node * add_new_word_to_tree(struct node *root, const struct node * node)
{
    if (!root)
    {
        return node;
    }

    int cmp_result = strcmp(node->value->word, root->value->word);

    if (cmp_result < 0)
    {
        /*code*/
    }
}
