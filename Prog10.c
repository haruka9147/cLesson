#include <stdio.h> // C standard lib
#include "multiply.h" // your header
#define SQUARE(x) multiply(x, x) // -> SQUARE can only use pass same value

//int multiply(int, int);

int main()
{
    printf("%d\n", SQUARE(10)); // -> multiply(10, 10)
    return 0;
}

// int multiply(int a, int b)
// {
//     return a * b;
// }