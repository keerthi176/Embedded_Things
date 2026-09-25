// C program to explain the pointer reversal.

#include <stdio.h>

void modify(int **pp, int *p_new) {
    *pp = p_new;
}

int main(void) 
{
    int a = 10, b = 20;
    int *ptr = &a;

    modify(&ptr, &b);
    *ptr = 30;

    printf("a=%d, b=%d\n", a, b);
    return 0;
}