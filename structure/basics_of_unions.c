#include"stdio.h"
#include "stdint.h"

uint16_t add(uint8_t a, uint16_t b);

typedef union {
 
    //0000 0000
    // 128 64 32 16 8421
    uint8_t value1;
    uint16_t value2;
    // 2 byte:memory  value1 value2
    
}ranges;


uint16_t add(uint8_t a, uint16_t b)
{
    uint16_t c;
    c = a+b;
    return c;
}

int main()
{
    ranges names;

    // names.value1 = 16;
    names.value2 = 2056; 
    
    printf("value of the number:%d\n", names.value2);

    uint16_t c = add(names.value1, names.value2);

    printf("print the value of c:%d\n", c);
    return 0;
}