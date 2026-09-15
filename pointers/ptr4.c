// write a C program using only pointers, find the sum of arr[] = {10,20,30,40,50};

#include <stdio.h>

int main() 
{

    int arr[5]   = {10,20,30,40,50};
    int *ptr_arr = arr;
    int sum;
    
    for(int i=0;i<5;i++)
    {
        sum = sum + (*ptr_arr++);
    }
    
    printf("%d\n", sum);

    return 0;
}
