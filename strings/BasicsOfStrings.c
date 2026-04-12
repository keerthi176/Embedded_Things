// Online C compiler to run C program online
#include <stdio.h>
#include "string.h"

int main() {

    char str[] = "Hello World";
    char str2[13];
    char str3[13];
    char str4[50] = "Hi ";
    
    printf("To print the length of the string:%d\n", strlen(str));
    
    printf("Print the size of the string:%d\n", sizeof(str));
    
    strcpy(str2, str);
    
    memcpy(str3, str, 12);
    
    printf("Print the string 2:%s\n", str2);
    printf("Print the string fromt he memcpy:%s\n", str3);
    
    // str cat.
    strcat(str4, str2);
    printf("Concatenated string is:%s\n", str4);
    
    int res = strcmp(str4, str);
    printf("Print the result of the compared string1:%d\n", res);
    
    if(res == 0)
    {
        printf("Both are equal\n");
    }
    else
    {
        printf("Both the strings are not equal\n");
    }
    
    int res1 = strcmp(str2,str3);
    printf("Print the result of the compared string2:%d\n", res1);
    
    if(res1 == 0)
    {
        printf("Both are equal\n");
    }
    else
    {
      printf("Both the strings are not equal\n");
    }
    
    return 0;
}