#include <stdio.h>
#include <sys/types.h>

int main()
{
    puts("Please enter a line of text");

    char * buffer = NULL;
    size_t len = 0;
    ssize_t read = getline(&buffer, &len, stdin);

    printf("Read string: %s", buffer);
    printf("Buffer size: %zu\n", len);
    printf("String size: %zd\n", read);

    return 0;
}
