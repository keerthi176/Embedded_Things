
#include <stdio.h>
#include "stdint.h"

int main()
{
    // 0000 1010
    uint16_t a = 10;
    // 1010
    int8_t b = 10;
    
    printf("Print the 16 bit value:%d\n", a);
    printf("Print the 8 bit value:%d\n", b);

    if(a == b)
    {
        printf("Both are equal\n");
    }
    else
    {
        printf("Both are not equal\n");
    }
    return 0;
}