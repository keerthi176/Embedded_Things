// program to understand dynamic memory allocation.
#include"stdio.h"
#include "stdlib.h"

int main()
{
    int *malloc_ptr;

    malloc_ptr = malloc(5 * sizeof(int));

    if(malloc_ptr == NULL)
    {
        printf("Memory did not initialize\n");
    }
    
    printf("memory has allocated\n");

    for(int i = 0; i < 5; i++)
    {
        malloc_ptr[i] = i + 1;
        printf("Value stored inside the memory:%d\n", malloc_ptr[i]);
    }
    
    free(malloc_ptr);
    
    return 0;
}