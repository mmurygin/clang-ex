#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/words-binary-tree.h"

void add_node_to_tree(struct node *root, struct node *node);

struct word_key *create_word_key(const char *word)
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

struct node * add_new_word_to_tree(struct node *root, const char *word)
{
    struct word_key * word_key = create_word_key(word);
    struct node * node = create_new_node(word_key);

    add_node_to_tree(root, node);

    return node;
}

void add_node_to_tree(struct node *root, struct node * node)
{
    if (!root)
    {
        return;
    }

    int cmp_result = strcmp(node->value->word, root->value->word);

    if (cmp_result < 0)
    {
        if (root->left)
        {
            add_node_to_tree(root->left, node);
        }
        else
        {
            root->left = node;
        }
    }
    else if (cmp_result > 0)
    {
        if (root->right)
        {
            add_node_to_tree(root->right, node);
        }
        else
        {
            root->right = node;
        }
    }
    else
    {
        printf("Error: node for word \"%s\" already in the tree", node->value->word);
    }
}

struct node *get_node_by_word(struct node *root, const char *word)
{
    if (!root)
    {
        return NULL;
    }

    int cmp_result = strcmp(word, root->value->word);

    if (cmp_result < 0)
    {
        return get_node_by_word(root->left, word);
    }
    else if (cmp_result > 0)
    {
        return get_node_by_word(root->right, word);
    }
    else
    {
        return root;
    }
}
