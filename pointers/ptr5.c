// Program: Using pointers find the largest numbers
#include <stdio.h>

int main(void) 
{
    int arr[6]   = {12,45,89,23,90,1};
    int *ptr_arr = arr;
    
    for(int i = 0; i<6; i++)
    {
        if(arr[i] > *ptr_arr)
        {
            ptr_arr = &arr[i];
        }
    }
    
    printf("%d\n", *ptr_arr);
    
    return 0;
}
