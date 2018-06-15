#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "include/words-binary-tree.h"

#define MAX_WORD_LEN 100

int getword(char *dst, int max_len);
void print_word_keys(const struct node *root);

int main()
{
    struct node *root = NULL;
    char word[MAX_WORD_LEN + 1];
    while (getword(word, MAX_WORD_LEN) != EOF)
    {
        if (!root)
        {
            root = add_new_word_to_tree(NULL, word);
            continue;
        }

        struct node *node = get_node_by_word(root, word);
        if (node)
        {
            node->value->count++;
            continue;
        }

        add_new_word_to_tree(root, word);
    }

    print_word_keys(root);

    return 0;
}

void print_word_keys(const struct node *root)
{
    if (root)
    {
        printf("%s: %d\n", root->value->word, root->value->count);
        print_word_keys(root->left);
        print_word_keys(root->right);
    }
}

int getword(char *dst, int max_len)
{
    int c;
    int i = 0;
    while (i < max_len && (c = getchar()) != EOF && !isspace(c) && c != '\n' && c != '\t')
    {
        dst[i++] = c;
    }

    dst[i] = '\0';

    if (c == EOF)
    {
        return EOF;
    }

    return i;
}
