// Program to find the system endianess using pointer dereferencing

#include <stdio.h>  

int main() {
    unsigned int int_var = 0x12345678;
    char *char_var_ptr = (char*)&int_var; // Create a char pointer pointing to the address of int_var

    if (*char_var_ptr) {

        printf("Little Endian:0x%02X\n", *char_var_ptr); // If the first byte is 1, it's little endian

    } else {
        
        printf("Big Endian:0x%02X\n", *char_var_ptr); // If the first byte is 0, it's big endian
    }

    return 0;
}