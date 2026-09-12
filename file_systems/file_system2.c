// Program to read and write the files in runtime.

#include"stdio.h"

int main(void)
{
    FILE *file_ptr;
    char char_buff[100];

    file_ptr = fopen("text_file.txt","r");

    while(fscanf(file_ptr, "%*s %*s %s", char_buff) == 1)
    {
        printf("%s\n", char_buff);
    }

    return 0;
}