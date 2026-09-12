#include "stdio.h"

int n = 1;
int arr[0];

int main()
{
    printf("Enter the size of the array:");
    scanf("%d\n", &n);
    

    for(int i = 0; i<n; n++)
    {
        printf("Enter the values of the array:%d\n", n);
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i<n;i++)
    {
         printf("value:%d\n", arr[i]);
    }

}