#include <stdio.h>
#include <stdlib.h>

int main()
{ 
    int a,b;
    printf("enter 2 no\n");
    scanf("%d%d",&a,&b);

    printf("relational operator\n");

    if(a>b)
    {
        printf("a:%d and b:%d, output:passed\n",a,b);
    }
    else
    {
        printf("a:%d and b:%d, output:Failed\n",a,b);
    }

    printf("%d < %d = %d\n",a,b,a<b);
    printf("%d >= %d = %d\n",a,b,a>=b);
    printf("%d <= %d = %d\n",a,b,a<=b);
    printf("%d  != %d = %d\n",a,b,a!=b);
    printf("%d  == %d = %d\n",a,b,a==b);
    
    return 0;
}