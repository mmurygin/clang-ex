#include <stdio.h>
#include "include/binary-tree.h"


int main()
{
    struct node * root = init_tree_from_stdin();

    printf("Traverse Deep: ");
    traverse_deep(root);
    printf("\n");

    printf("Max depth: %d\n", get_max_tree_depth(root));

    return 0;
}
