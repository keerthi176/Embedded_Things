#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;
    int *temp;

    /* =========================================
       1. MALLOC
       ========================================= */

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(*arr));

    if (arr == NULL)
    {
        printf("malloc failed!\n");
        return 1;
    }

    printf("\nMemory allocated using malloc()\n");

    /*
       malloc() does NOT initialize the memory.
       Therefore, we should assign values before reading them.
    */

    for (int i = 0; i < n; i++)
    {
        arr[i] = (i + 1) * 10;
    }

    printf("Values after malloc:\n");

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    /* =========================================
       2. CALLOC
       ========================================= */

    int *zero_arr;

    zero_arr = calloc(n, sizeof(*zero_arr));

    if (zero_arr == NULL)
    {
        printf("\ncalloc failed!\n");
        free(arr);
        return 1;
    }

    printf("\nMemory allocated using calloc()\n");

    /*
       calloc() initializes all allocated bytes to zero.
    */

    printf("Values after calloc:\n");

    for (int i = 0; i < n; i++)
    {
        printf("zero_arr[%d] = %d\n", i, zero_arr[i]);
    }


    /* =========================================
       3. REALLOC
       ========================================= */

    int new_n;

    printf("\nEnter new size: ");
    scanf("%d", &new_n);

    /*
       Don't directly do:

           arr = realloc(arr, new_n * sizeof(*arr));

       Instead use a temporary pointer.
    */

    temp = realloc(arr, new_n * sizeof(*arr));

    if (temp == NULL)
    {
        printf("realloc failed!\n");

        free(arr);
        free(zero_arr);

        return 1;
    }

    arr = temp;

    /*
       realloc() preserves the old data that fits
       in the new allocation.

       If the new size is larger, the newly added
       memory is NOT initialized.
    */

    printf("\nMemory resized using realloc()\n");

    /*
       Initialize the newly available elements.
    */

    if (new_n > n)
    {
        for (int i = n; i < new_n; i++)
        {
            arr[i] = (i + 1) * 10;
        }
    }

    printf("Values after realloc:\n");

    for (int i = 0; i < new_n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    /* =========================================
       4. FREE
       ========================================= */

    free(arr);
    free(zero_arr);

    arr = NULL;
    zero_arr = NULL;

    printf("\nMemory released using free()\n");

    return 0;
}