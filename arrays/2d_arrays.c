//Program to explain 2D array.
#include "stdio.h"

int main()
{
    // single dimensional array.
    int arr[3][3] = {{20,40,60},
                    {10, 30, 50},
                    {30, 80, 90}
    };
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Print the array[%d][%d]:%d\n",i,j, arr[i][j]);
        }
    }
    
    printf("Print the any value in the array:%d\n", arr[0][2]);
    
}