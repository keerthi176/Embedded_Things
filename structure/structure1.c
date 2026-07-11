#include <stdio.h>
#include "string.h"

// Used for structure packing.
#pragma pack(1)

typedef struct {
    
    char names[8];  // 8 bytes.
    int rollNo;     // 4 bytes.
    int marks;      // 4 bytes.
    
}marks_sheet;

typedef union {

    char names[20]; // 20 bytes.
    int rollNo;     // 4 bytes.
    int marks;      // 4 bytes.
    
}marks_sheet2;


int main()
{
    marks_sheet school;
    marks_sheet2 school2;
    
    strcpy(school.names,"Shashank");
    school.rollNo = 10;
    school.marks = 70;
    
    
    printf("Size of the structure:%d\n", sizeof(school));
    printf("Size of the union:%d\n", sizeof(school2));
    
    printf("name in the marks sheet:%s\n", school.names);
    printf("roll Number in the marks sheet:%d\n", school.rollNo);
    printf("Marks in the marks sheet:%d\n", school.marks);

    // strcpy(school2.names,"Shashank");
    school2.rollNo = 10;
    // school2.marks = 80;
    
    // printf("name in the marks sheet:%s\n", school2.names);
    printf("roll Number in the marks sheet:%d\n", school2.rollNo);
    printf("Marks in the marks sheet:%d\n", school2.marks);
    
    return 0;
}