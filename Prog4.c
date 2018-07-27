#include <stdio.h>
#define PI 3.1416

int main()
{
    int age;
    char grade;
    scanf("%d %c\n", &age, &grade); // ctrl + d = EOF

    printf("Your age is %d\n", age);
    printf("Your grade is %c\n", grade);

    int dec = 20 /* base 10 */, oct = 020 /* base 8 */, hex = 0x20 /* base 16 */, bin = 0b10101 /* base 2 */;
    printf("dec=%d, oct=%d, hex=%d, bin=%d\n", dec, oct, hex, bin);
    printf("dec=%d, oct=%o, hex=%x\n", dec, oct, hex); // change to decimal number

    float pi = 3.14160000;
    printf("PI is %.2f\n", pi);
    printf("PI is %le\n", pi);
    printf("PI is %lg\n", pi);

    const int sunday = 0; /* no longer available for left side value of = */
    // left side value == right side value
    return 0;
}