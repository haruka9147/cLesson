#include <stdio.h>

int main(void)
{
    short a = 0x6ed9; // 2 bytes = 16 bits
    short b = 0x5d27;

    printf("0x%x\n", a & b); // AND
    printf("0x%x\n", a | b); // OR
    printf("0x%x\n", ~a); // NOT
    printf("0x%x\n", a ^ b); // only each value different is true
}