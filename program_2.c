#include<stdio.h>
int main()
{
    int n,i,j,count=1;
    printf("enter the number of rows\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)   
    {
        for(j=1;j<=i;j++)
        {
            printf("\t%d",count++);
        }
        
        count = 1;
        printf("\n");
    }
    return 0;
}