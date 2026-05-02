#include <stdio.h>

int main()
{
    int a = 10;
    float b = 5.5;

    void *ptr;

    ptr = &a;
    printf("Integer value: %d\n", *(int *)ptr);   // cast to int*

    ptr = &b;
    printf("Float value: %.2f\n", *(float *)ptr); // cast to float*

    return 0;
}