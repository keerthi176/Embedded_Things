
#include <stdio.h>

int main() {

   unsigned int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   unsigned int *int_ptr = arr;
    
    printf("Value inside the pointer:%d\n", int_ptr);

   for(int i =0; i<10; i++)
   {
        printf("Value inside the pointer:%d\n", *int_ptr);
        int_ptr++;

   }

    return 0;
}