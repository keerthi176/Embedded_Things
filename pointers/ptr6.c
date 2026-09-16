// Write a C program: Using pointers reverse the numbers.

#include "stdio.h"

int main()
{
    int arr[5] = {10,20,30,40,50};
    int *ptr_arr = arr;
    int arr2[5];
    
    for(int i=4; i>-1;i--)
    {
        arr2[i] = *ptr_arr;
        ptr_arr++;
        // printf("%d\n",arr2[i]);
    }

    for(int i=0;i<5;i++)
    {
        arr[i] = arr2[i];
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
