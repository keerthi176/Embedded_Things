// C program to demonstate the use of offsetof macro.
#include <stdio.h>
#include "stddef.h"

struct example {
    
    char a;     // 1 byte.
                // + 3 byte structure padding.
    int b;      // 4 byte.
    double c;   // 8 byte.
    
};

int main(void)
{
    printf("a:%zu\n", offsetof(struct example, a));
    printf("a:%zu\n", offsetof(struct example, b));
    printf("a:%zu\n", offsetof(struct example, c));
    
    printf("Total size of the struct:%zu\n", sizeof(struct example));

    return 0;
}