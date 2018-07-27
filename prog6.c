#include <stdio.h>

int main()
{
    int i = 5, j = 4, k;
    double f = 5.0, g = 4.0, h;

    k = i / j;
    printf("%i\n", k);
    h = f / g;
    printf("%f\n", h);
    h = i / j; // equal is execute last
    printf("%f\n", h);

    // Boolean - there is no boolean type in C, use number!
    // The value of 0 (or 0.0) is false
    // Any other value, 1, -1, 0.3, -12.5, is true.

    // 10 > k -> 1, if it's false, return 0. m > 0 is correct way
    char x;
    if((x = getChar()) != EOF)
    {
        printf("Hello");
    }

    // Bitwise Operator: operators for bits.
    // && || !
    
    return 0;
}