#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *init_tree_from_stdin();
int get_max_tree_depth(struct node *root);
void traverse_deep(const struct node *root);

#endif
