#include <stdio.h>
#include <limits.h>

//int lower(char c); declare function protype

int lower(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return c + 'a' - 'A';
    }
    return c;
}

int main()
{
    char c;
    printf("Please enter character: ");
    scanf("%c", &c);

    printf("Upper case: %c\n", lower(c));

}