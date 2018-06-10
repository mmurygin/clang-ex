#include <stdio.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

int main()
{
    int i = 12;
    int c = 12;
    printf("&i = %p; c = %p\n", &i, &c);

    i = 18;
    printf("&i = %p; c = %p\n", &i, &c);

    for (int i = 0; i < 10; i++)
    {
        int b = 89;
        printf("&b = %p\n", &b);
    }

    struct node root = { 0, 0, 0 };
    printf("%d %p %p\n", root.value, root.left, root.right);
    return 0;
}
