#include <stdio.h>

void reverse(int arr[])
{
    printf("The elements of array in REVERSE order are:\n");
    for(int i = 9; 0 <= i; i--)
    {
        if(i == 9)
        {
            printf("[%d,", arr[i]);
        }
        else if(i == 0)
        {
            printf("%d]\n", arr[i]);
        }
        else
        {
            printf("%d,", arr[i]);
        }
    }
}
void sum(int *arr)
{
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        sum += *(arr + i);
    }
    printf("The sun of array is %d\n", sum);
}
void sum2(int *x, int *y)
{
    printf("The sum of %d and %d is: %d", *x, *y, *x + *y);
}
int main()
{
    // // 1)
    // int arr1[10] = {};
    // int arr2[10];
    // //int *p_arr2 = arr2;
    // int i = 0;
    // for(int i = 0; i < 10; i++)
    // {
    //     printf("Please enter number: ");
    //     scanf("%d\n", &arr1[i]);
    //     arr2[i] = arr1[i];
    // }

    // printf("The elements stored in the FIRST array are:\n");
    // for(int i = 0; i < 10; i++)
    // {
    //     if(i == 0)
    //     {
    //         printf("[%d,", arr1[i]);
    //     }
    //     else if(i == 9)
    //     {
    //         printf("%d]\n", arr1[i]);
    //     }
    //     else
    //     {
    //         printf("%d,", arr1[i]);
    //     }
        
    // }

    // printf("The elements stored in the SECOND array are:\n");
    // for(int i = 0; i < 10; i++)
    // {
    //     if(i == 0)
    //     {
    //         printf("[%d,", arr2[i]);
    //     }
    //     else if(i == 9)
    //     {
    //         printf("%d]\n", arr2[i]);
    //     }
    //     else
    //     {
    //         printf("%d,", arr2[i]);
    //     }
        
    // }

    // // 2)
    // reverse(arr2);

    // // 3)
    // sum(arr2);

    int x, y;
    printf("Input the first number:");
    scanf("%d\n", &x);

    printf("Input the second number:");
    scanf("%d\n", &y);

    sum2(&x, &y);

    return 0;
}