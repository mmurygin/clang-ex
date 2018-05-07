#include <stdio.h>

#define MAX_WORD_LENGTH 10
#define HISTOGRAM_CHAR 'I'

void fill_words_array(int * arr) {
    char c;
    int length = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == ' ' || c == '\t')
        {
            if (length == 0)
                continue;

            if (length > MAX_WORD_LENGTH)
            {
                length = MAX_WORD_LENGTH;
            }

            ++arr[length - 1];
            length = 0;
        }
        else
        {
            ++length;
        }
    }
}

void print_histogram(int * arr) {
    int max_element = 0;

    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    for (int current = max_element; current > 0; --current) {
        for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
            putchar(' ');

            arr[i] >= current ? putchar(HISTOGRAM_CHAR) : putchar(' ');

            putchar(' ');
        }
        putchar('\n');
    }
}

void print_footer() {
    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        printf("---");
    }

    putchar('\n');

    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        printf(" %d ", i + 1);
    }
}

int main() {
    int arr[MAX_WORD_LENGTH] = {0};

    fill_words_array(arr);

    putchar('\n');

    print_histogram(arr);

    print_footer();

    putchar('\n');

    return 0;
}
