#include<stdio.h>

void display(int *ptr, int size)
{
        for(int i=0; i<size;i++)
        {
            printf("%d", *ptr);
            ptr++;
        }

        printf("\n");
}

int main()
{
    int arr[] = {1,2,3,4,5};

    display(arr, 5);

    return 0;
}