// file on function pointers in C.
// Syntax - void *fp(void);

#include"stdio.h"

void print_string(void)
{
    printf("Hello Embedded World!\n");
}

int main()
 {

    void (*fp)(void);
    fp = &print_string;
    
    fp();
    return 0;
}