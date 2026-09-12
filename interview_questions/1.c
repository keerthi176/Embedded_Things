    //! How to find the length of the string without using strlen.
#include"stdio.h"

int my_strlen(char *string);

int main()
{
    char string_arr[15] = "Hello_embedded";

    printf("size of the string:%d\n", sizeof(string_arr));

    for(int i = 0; i<=sizeof(string_arr); i++)
    {
        printf("character:%c\n", string_arr[i]);
    }

    // Here string length is calculated using non library function.
    int no_of_ch = my_strlen(string_arr);
    printf("number of the character present in the string:%d\n", no_of_ch);

    return 0;
}

int my_strlen(char *string)
{
    int count;

    while(*string != '\0')
    {
        count++;
        string++;
    }

    return count;
}