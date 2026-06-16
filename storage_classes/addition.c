#include"stdio.h"
#include"addition.h"
#include "stdlib.h"

int c;
//auto.
int d;

volatile int rn;

int add(int a, int b)
{
    c = a+b;

    return c;
}


void random_fun()
{
    for(int i=0;i<200;i++)
    {
        rn++;
    }
}