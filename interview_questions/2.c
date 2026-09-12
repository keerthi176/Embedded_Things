// program to swap two numbers.

#include"stdio.h"

int main(void)
{
    int a = 20, b = 10;

    printf("print the before swapped numbers a:%d b :%d\n", a, b);
    
    a = a+b;
    b = a-b;
    a = a-b;

    printf("print the after swapped numbers a:%d b :%d\n", a, b);

    return 0;
}