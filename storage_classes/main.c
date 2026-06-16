#include"stdio.h"
#include "addition.h"

static int add_var;
extern int c;
extern int rn;

int main()
{
    register int d;

    printf("The value of the variable is:%d\r\n", c);
    add_var = add(5,6);
    d = add_var;
    printf("The address of the nornaml variable:%ls\r\n", &c);
    random_fun();
    printf("The value of the variable is:%d\r\n", add_var);
    printf("The value of the variable is:%d\r\n", c);
    printf("The value of the volatile variable is:%d\r\n", rn);

    return 0;
}