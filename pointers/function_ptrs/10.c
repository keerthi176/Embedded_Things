// C program to demonstrate the use of double pointers using function parameters in C.

#include <stdio.h>
#include <stdlib.h>

void allocateMemory(int **ptr)
{
    *ptr = (int *)malloc(sizeof(int));

    if (*ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    **ptr = 100;
}

int main(void)
{
    int *p = NULL;

    allocateMemory(&p);

    if (p != NULL)
    {
        printf("Value = %d\n", *p);

        free(p);
        p = NULL;
    }

    return 0;
}