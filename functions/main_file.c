#include "stdio.h"
#include "addition.h"

int a,b,d;
char c;

void main()
{
	printf("Enter the numbers for execution:");
	scanf("%d %d", &a, &b);
	
	d = addition(a,b);
	
	printf("The added value is:%d", d);
}