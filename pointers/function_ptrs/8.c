// program to demostrate the use of double pointers in C.

#include"stdio.h"

int main()
{
    int a = 10;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;

    printf("Value of a: %d\n", a);
    printf("Value of a using ptr1: %d\n", *ptr1);
    printf("Value of a using ptr2: %d\n", **ptr2);

    return 0;
}