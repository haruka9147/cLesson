#include <stdio.h>
#include <limits.h>

int main()
{
    int r;
    int h;
    float pi = 3.14159265335890;
    printf("Please enter radius: ");
    scanf("%d", &r);
    printf("Please enter height: ");
    scanf("%d", &h);

    float area = pi * r * r;
    printf("Area is %f\n", area);

    float volume = area * h;
    printf("Volume is %f\n", volume);

}