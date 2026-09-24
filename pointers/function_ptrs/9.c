// program todemostrate the double pointers in function parameters in C.

#include"stdio.h"

void double_pointers(int ***ptr3)
{
    printf("Value using triple pointer: %d\n", ***ptr3);
}

int main()
{
    int a = 10;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;

    double_pointers(ptr3);

    return 0;
}