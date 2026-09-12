#include"stdio.h"
#include "stdlib.h"

int main(void)
{
    int *ptr;
    int arr[4];
    
    ptr = malloc(4*sizeof(int));
    
    for(int i = 0;i<6;i++)
    {
        ptr[i] = i*10;
        printf("print the stored values:%d\n", ptr[i]);
    }
    
    free(ptr);
    
return 0;
    
}