// Accessing a file fro charcters updation.
#include "stdio.h"

int main()
{
    FILE *fptr;
    char char_arr[50] = "Hello_World\n";

    // syntax to open the file.
    fptr = fopen("text_file.txt","w");

    fputs(char_arr, fptr);

    fclose(fptr);

}