#include <stdio.h>

  int x= 2;
    int y= 3;
    int z =2;

int main() {
  

  

    int arr[2][3][2] = { { { 1, 1 }, { 2, 3 }, 
                       { 4, 5 } }, { { 6, 7 }, 
                       { 8, 9 }, { 10, 11 } } };

                       printf("sizeof x:%d,y:%d and z:%d\n", sizeof(x), sizeof(y), sizeof(z));
  	// Loop through the depth
    for (int i = 0; i < 2; ++i) {
      
      	// Loop through the 
      	// rows of each depth
        for (int j = 0; j < 2; ++j) {
          
          	// Loop through the 
          	// columns of each row
            for (int k = 0; k < 3; ++k)
                printf("arr[%i][%i][%i] = %d   ", i, j, k,
                       arr[i][j][k]);
          	printf("\n");
        }
      printf("\n\n");
    }
    return 0;
}