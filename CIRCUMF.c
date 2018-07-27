#include <stdio.h>
#include <limits.h>

int main()
{
    int r;
    float pi = 3.14159265335890;
    printf("Please enter radius: ");
    scanf("%d", &r);

    float circum = 2 * pi * r;
    printf("Circum = %f", circum);

}