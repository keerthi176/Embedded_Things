// C program to demonstate the use of the double pointers in function parameters in C.

#include <stdio.h>
#include <stdlib.h>

int create_buffer(int **buffer, int size)
{
    *buffer = malloc(size * sizeof(int));

    if (*buffer == NULL)
    {
        return -1;
    }

    return 0;
}

int main(void)
{
    int *data = NULL;

    if (create_buffer(&data, 5) == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            data[i] = (i + 1) * 10;
        }

        for (int i = 0; i < 5; i++)
        {
            printf("%d ", data[i]);
        }

        free(data);
        data = NULL;
    }

    return 0;
}