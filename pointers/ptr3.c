#include "stdio.h"
int temp_data(int *ptr);


int temp_data(int *ptr)
{
    int var = 10;

    *ptr = var;
    return 0;
}

int main()
{
    int ptr_var;
    temp_data(&ptr_var);

    printf("The value of the pointer variable:%d\r\n", ptr_var);
    return 0;
}