/*

Question 1: Bare-Metal GPIO & Clock Enable via Pointer Structs Problem: 
    On an STM32 Nucleo board, the user LED (LD2) is typically connected to PA5 (Port A, Pin 5). Write a bare-metal C program using structure pointers to. 
        1. Enable the clock for GPIOA in the RCC (Reset and Clock Control) register (RCC_AHB1ENR at offset 0x30 from base 0x40023800). 
        2. Configure PA5 as a General Purpose Output mode in GPIOx_MODER. 
        3. Toggle the LED every ~500ms using a simple software delay loop, accessing GPIOx_ODR directly.

*/

#include <stdint.h>
#include <stddef.h>
#include "stdio.h"

typedef struct{

    volatile uint32_t reserved[12]; // Offset 0x00 to 0x30
    volatile uint32_t AHB1ENR;       // Offset 0x30: AHB1 peripheral clock enable register

} RCC_TypeDef;

typedef struct {

    volatile uint32_t MODER;   // GPIO port mode register
    volatile uint32_t OTYPER;  // GPIO port output type register
    volatile uint32_t OSPEEDR; // GPIO port output speed register
    volatile uint32_t PUPDR;   // GPIO port pull-up/pull-down register
    volatile uint32_t IDR;     // GPIO port input data register
    volatile uint32_t ODR;     // GPIO port output data register
    volatile uint32_t BSRR;    // GPIO port bit set/reset register
    volatile uint32_t LCKR;    // GPIO port configuration lock register
    volatile uint32_t AFR[2];  // GPIO alternate function registers (AFRL, AFRH)

} GPIO_TypeDef;

// ! Define base addresses for RCC and GPIOA
#define RCC_BASE        (RCC_TypeDef *)0x40023800UL
#define GPIOA_BASE      (GPIO_TypeDef *)0x40020000UL  // This is not mentioned in the question but refer the refrence manual for STM32F4 series.

void delay(volatile uint32_t count) {
    while (count--) {
        __asm volatile ("nop");
    }
}

int main(void)
{
    // 1. Enable the clock for GPIOA in RCC_AHB1ENR
    RCC_BASE->AHB1ENR |= (1U << 0); // Set bit 0 to enable GPIOA clock

    // 2. Configure PA5 as General Purpose Output mode in GPIOA_MODER
    GPIOA_BASE->MODER &= ~(0x3U << (5 * 2)); // Clear MODER5 bits
    GPIOA_BASE->MODER |= (0x1U << (5 * 2));  // Set MODER5 to 01 (General Purpose Output)

    // 3. Toggle the LED every ~500ms using a simple software delay loop
    while (1) 
    {
        GPIOA_BASE->ODR ^= (1U << 5); // Toggle PA5 output state
        delay(500000); // Simple software delay loop (~500ms)
    }

    return 0;
}