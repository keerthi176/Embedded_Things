// program on function pointers using input arguments in C.

#include"stdio.h"   

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*fp)(int, int);
    fp = &add;
    
    int result = fp(10, 20);
    printf("Result: %d\n", result);
    
    return 0;
}