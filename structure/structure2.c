
#include <stdio.h>
#include "stdint.h"

typedef union {
    
    uint16_t a;
    //0000 1010
    
    uint8_t b;
    //1010
}temp;

int main()
{
    printf("size of union is:%d\n", sizeof(temp));
    
    temp var;
    
    var.b = 200;
    
    // 1000
    printf("print the var:%d\n", var.a);
    
    return 0;
}