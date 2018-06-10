#include <stdio.h>
#include "include/binary-tree.h"


int main()
{
    struct node * root = init_tree_from_stdin();

    printf("Pre order: ");
    traverse_pre_order(root);

    printf("\n");

    return 0;
}
