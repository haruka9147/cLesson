#include <stdio.h>
#include <limits.h>

int sum(int a, int b)
{
    return a + b;
}

int diff(int a, int b)
{
    return a - b;
}

int prod(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}

int rem(int a, int b)
{
    return a % b;
}

int main()
{
    int a;
    int b;

    printf("Enter integer: \n");
    scanf("%d", &a);

    printf("Enter integer: \n");
    scanf("%d", &b);

    printf("sum : %d\n", sum(a, b));

    printf("diff : %d\n", diff(a, b));

    printf("product : %d\n", prod(a, b));

    printf("divide : %d\n", div(a, b));

    printf("remainder : %d\n", rem(a, b));

    printf("anding: %d\n", a & b);
    printf("oring: %d\n", a | b);
    printf("exclusive oring: %d\n", a ^ b);

    printf("Left shift: %d\n", a << b);
    printf("Right shift: %d\n", a >> b);

    return 0;
}