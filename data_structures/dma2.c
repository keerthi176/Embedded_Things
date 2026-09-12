// program to understand dynamic memory allocation(Calloc).
#include"stdio.h"
#include "stdlib.h"

int main()
{
    int *calloc_ptr;

    calloc_ptr = calloc(5, sizeof(int));

    if(calloc_ptr == NULL)
    {
        printf("Memory did not initialize\n");
    }
    
    printf("memory has allocated\n");

    for(int i = 0; i < 5; i++)  
    {
        calloc_ptr[i] = i + 1;
        printf("Value stored inside the memory:%d\n", calloc_ptr[i]);
    }
    
    free(calloc_ptr);
    
    return 0;
}