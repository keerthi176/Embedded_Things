// C program to send 16 bit value using 8 bit integer.
#include <stdio.h>
#include "stdint.h"

int main()
{
    uint16_t a;
    uint8_t b[2];
    uint16_t d;

    // 1024 512 256 128 64 32 16 8421
    // 0000 0011 1110 1000
    a = 1000;
    
    printf("value of a:%d\n", a);
    
    #if 1
    // splitting the packets 
    // bitwise operations has to be done here in order send the value.
    b[0] = a;
    b[1] = (a>>8);

    // reconstructing the packet.
    // d = (b || c);
    d = ((b[1]<<8) | b[0]);

    // printf("value of 8 bit integer:%d\n", b);
    // printf("value of 8 bit integer:%hhu\n", c);
    printf("value of 16 bit integer:%u\n", d);
#endif

    return 0;
}