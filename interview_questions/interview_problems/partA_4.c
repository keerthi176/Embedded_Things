// Q 4. What is the output of this program?

#include "stdio.h"

int main(void)
{
    char *vec[] = {"Alpha", "Beta", "Gamma", "Delta"};
    char **app[] = {vec + 3, vec + 2, vec + 1, vec}; 
    char ***pp = app;

    printf("%s", **++pp);
    printf("%s ", *--*++pp + 3);
    printf("%s\n", pp[-1][1]);

    return 0;
}