// C program to explain the structure pointer of different type.

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

typedef struct{
    
    uint8_t rollno;
    char     names[10];
    double   marks;
    
}classA;

typedef struct{
    
    uint8_t rollno;
    char    names[10];
    double  marks;

}classB;

int main()
{
    classB var = {10, "Alice", 30};
    
    classA *mem_ptr = malloc(sizeof(classA));
    
    // classA *list1;
    classB *list2 = &var;
    
    *mem_ptr = (*(classA *)list2);
    
    printf("rollno:%u\n", mem_ptr->rollno);
    
    free(mem_ptr);
    
    return 0;
}