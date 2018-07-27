#include <stdio.h>

struct Car
{
    int price;
    char *brand;
};

struct node
{
    int value;
    struct node *next;
};
// typedef char *string
// typedef struct { int price; char *brand;} Car;

int main(int argc,char *argv[])
{
    struct Car car1;
    car1.price = 10000;
    car1.brand = "TOYOTA";
    

    // Linked List
    struct node one; //10
    struct node two; //1
    struct node three; //2
    one.value = 10;
    one.next = &two;
    //*(one.next) = two;
    two.value = 1;
    one.next = &three;
    three.value = 2;
    three.next = NULL;

    printf("Price: %d, Brand: %s\n", car1.price, car1.brand);
    printf("Element: %d\n", one.next->next->value);
    //printf("Element: %d\n", (*one.next).next->value);
    return 0;
}