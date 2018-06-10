#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node * fill_tree();
int get_tree_depth(const struct node *root);
struct node * get_new_node(int val);

int main()
{
    struct node * root = fill_tree();
    printf("Tree depth: %d", get_tree_depth(root));

    return 0;
}

struct node * fill_tree()
{
    int val;
    if (scanf("%d", &val) == EOF)
    {
        puts("Error: Can't get the root node");
    }

    struct node *root = get_new_node(val);

    while (scanf("%d", &val) != EOF)
    {
        fill_node(root, val);
    }

    return root;
}

void fill_node(struct node *node_to_fill, int value)
{
    if (node_to_fill->value > value)
    {
        if (node_to_fill->right == NULL)
        {
            node_to_fill->right = get_new_node(value);
        }
        else
        {
            fill_node(node_to_fill->right, value);
        }
    }
    else if (node_to_fill->value < value)
    {
        if (node_to_fill->left == NULL)
        {
            node_to_fill->left = get_new_node(value);
        }
        else
        {
            fill_node(node_to_fill->left, value);
        }
    }
    else
    {
        puts("Error: the values could not be equal");
    }
}

struct node * get_new_node(int val)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = val;

    return new_node;
}
