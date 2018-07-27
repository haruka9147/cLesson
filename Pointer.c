#include <stdio.h>

int main()
{
    char c = 'a';
    char *p = &c;

    printf("The memory address of c: %p\n", &c);
    printf("The value of p: %p\n", p);
    printf("The content of p: %c\n", *p);
    return 0;
}