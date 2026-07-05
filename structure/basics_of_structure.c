
// example which explains the structure basics.


#include <stdio.h>
#include"string.h"

// size of the struct 84
struct address_book{
    
    int road_num;
    char area_name[50];
    char city[30];
};

int main() {
    
    // page1 is the variable name of data type address_book.
    struct address_book page1;
    
    printf("Size of the structure is:%d\n", sizeof(page1));
    
    printf("===========================End of page 0======================\n");
    
    page1.road_num = 12;
    strcpy(page1.area_name,"suburban");
    strcpy(page1.city,"mysuru");
    
    printf("name of the road:%d\n", page1.road_num);
    printf("name of the area:%s\n", page1.area_name);
    printf("Name of the city:%s\n", page1.city );

    printf("===========================End of page 1======================\n");
    
    // page2 is the variable name of data type address_book.
    struct address_book page2;
    
    
    page2.road_num = 10;
    strcpy(page2.area_name, "majestic");
    strcpy(page2.city, "bengaluru");
    
    printf("Value of the road_num of page2 is:%d\n", page2.road_num );
    printf("road_num of page2 is:%s\n", page2.area_name );
    printf("City name in the page 2:%s\n", page2.city );

    return 0;
}