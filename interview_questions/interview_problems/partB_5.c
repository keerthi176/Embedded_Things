/*

    In ARM Cortex-M microcontrollers, vector table relocation is achieved by writing the vector table's base memory address to the Vector Table Offset Register 
    (VTOR, mapped at 0xE000ED08). Write a C function that takes a dynamic RAM array containing new ISR function pointers and
     updates the hardware VTOR register using pointers. What alignment rule must the new base address observe if the table contains 64 vectors?

*/