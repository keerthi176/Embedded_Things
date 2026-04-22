
#include <stdio.h>

int main() {

   unsigned int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   unsigned int *int_ptr = arr;
    
   int_ptr++;
    printf("Value inside the pointer:%d\n", int_ptr);
    printf("Value inside the pointer address:%d\n", *int_ptr);
    printf("Address of the pointer:%d\n", &int_ptr);
    printf("Address of the array variable:%d\n", &arr[0]);


    return 0;
}