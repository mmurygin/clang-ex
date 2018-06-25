#include <stdio.h>
#include <stdlib.h>
#include "include/binary-tree.h"

#define MAX_TREE_NODES 100

struct node *create_new_node(int val)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = val;

    return new_node;
}

int get_max_tree_depth(struct node *root)
{
    if (!root)
    {
        return -1;
    }

    int left_branch_depth = get_max_tree_depth(root->left);
    int right_branch_depth = get_max_tree_depth(root->right);

    return left_branch_depth > right_branch_depth ?
        left_branch_depth + 1 :
        right_branch_depth + 1;
}

int get_min_tree_depth(struct node *root)
{
    if (!root)
    {
        return -1;
    }

    int left_branch_depth = get_max_tree_depth(root->left);
    int right_branch_depth = get_max_tree_depth(root->right);

    return left_branch_depth > right_branch_depth ?
        right_branch_depth + 1 :
        left_branch_depth + 1;
}

void add_value_as_balanced_tree(struct node *root, int value)
{
    int left_branch_depth = get_min_tree_depth(root->left);
    int right_branch_depth = get_min_tree_depth(root->right);

    if (left_branch_depth == -1)
    {
        root->left = create_new_node(value);
        return;
    }
    if (right_branch_depth == -1)
    {
        root->right = create_new_node(value);
        return;
    }

    if (left_branch_depth <= right_branch_depth)
    {
        add_value_as_balanced_tree(root->left, value);
    }
    else
    {
        add_value_as_balanced_tree(root->right, value);
    }
}

void add_value_as_binary_tree(struct node *root, int value)
{
    if (root->value > value)
    {
        if (root->right == NULL)
        {
            root->right = create_new_node(value);
        }
        else
        {
            add_value_as_binary_tree(root->right, value);
        }
    }
    else if (root->value < value)
    {
        if (root->left == NULL)
        {
            root->left = create_new_node(value);
        }
        else
        {
            add_value_as_binary_tree(root->left, value);
        }
    }
    else
    {
        puts("Error: the values could not be equal");
    }
}

struct node *init_tree_from_stdin()
{
    int val;
    if (scanf("%d", &val) == EOF)
    {
        puts("Error: Can't get the root node");
    }

    struct node *root = create_new_node(val);

    while (scanf("%d", &val) != EOF)
    {
        add_value_as_binary_tree(root, val);
    }

    return root;
}

void traverse_deep(const struct node *root)
{
    if (root)
    {
        printf("%d ", root->value);
        traverse_deep(root->left);
        traverse_deep(root->right);
    }
}
