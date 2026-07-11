// Example for fetching a structure using a pointer

#include <stdio.h>
#include "string.h"

typedef struct {
    
    char names[8];  // 8 bytes.
    int rollNo;     // 4 bytes.
    int marks;      // 4 bytes.
    
}marks_sheet;

int main()
{
    marks_sheet school;
    
    strcpy(school.names,"Shashank");
    school.rollNo = 10;
    school.marks = 70;
    
    marks_sheet *ptr = &school;
    
    printf("name of the student:%s\n", ptr->names);
    printf("name of the roll number:%d\n", ptr->rollNo);
    printf("name of the marks:%d\n", ptr->marks);


    return 0;
}