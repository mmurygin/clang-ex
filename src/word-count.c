#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 20

struct key {
    char * word;
    int count;
};

static struct key keytab[] = {
    "break", 0,
    "case", 0,
    "char",  0,
    "const", 0,
    "include", 0,
    "int", 0,
    "return", 0,
    "static", 0,
};

static int keytab_length = sizeof(keytab) / sizeof(struct key);

int getword(char *dst, int max_len);
int binsearch(const char *word, int min, int max);
void print_keytabs();

int main()
{
    char word[MAX_WORD_LEN + 1];
    while (getword(word, MAX_WORD_LEN) != EOF)
    {
        int word_index = binsearch(word, 0, keytab_length);
        if (word_index != -1)
        {
            keytab[word_index].count++;
        }
    }

    print_keytabs();

    return 0;
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

void print_keytabs()
{
    for (int i = 0; i < keytab_length; i++)
    {
        printf("\"%s\": %d times\n", keytab[i].word, keytab[i].count);
    }
}

int binsearch(const char *word, int min, int max)
{
    int len = max - min;
    int middle = min + len / 2;

    int cmpResult = strcmp(word, keytab[middle].word);

    if (len == 1 && cmpResult != 0)
    {
        return -1;
    }

    if (cmpResult < 0)
    {
        return binsearch(word, min, middle);
    }

    if (cmpResult > 0)
    {
        return binsearch(word, middle, max);
    }

    return middle;
}
