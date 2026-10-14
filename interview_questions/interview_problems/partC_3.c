/*

        Question 3: UART Ring Buffer via Pointer Arithmetic Problem: Nucleo ST-LINK virtual COM port connects to USART2 (PA2 = TX, PA3 = RX). 
                    Implement a circular RX ring buffer and an interrupt handler that stores incoming serial bytes 
                    using pointer indexing without dropping data during rapid typing.

*/

#include <stdint.h>

#define RCC_BASE        (0x40023800UL)
#define GPIOA_BASE      (0x40020000UL)
#define USART2_BASE     (0x40004400UL)
#define NVIC_ISER1      (0xE000E104UL)

typedef struct {

    volatile uint32_t SR;   // Status register
    volatile uint32_t DR;   // Data register
    volatile uint32_t BRR;  // Baud rate register
    volatile uint32_t CR1;  // Control register 1
    volatile uint32_t CR2;  // Control register 2
    volatile uint32_t CR3;  // Control register 3
    volatile uint32_t GTPR; // Guard time and prescaler register

} USART_TypeDef;

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

typedef struct {

    volatile uint32_t reserved[12];
    volatile uint32_t AHB1ENR;       // Offset 0x30: AHB1 peripheral clock enable register
    volatile uint32_t reserved1[6];
    volatile uint32_t APB2ENR;       // Offset 0x44: APB2 peripheral clock enable register

} RCC_TypeDef;

#define BUFFER_SIZE 128
#define RCC             ((RCC_TypeDef *)RCC_BASE)
#define GPIOA           ((GPIO_TypeDef *)GPIOA_BASE)
#define USART2          ((USART_TypeDef *)USART2_BASE)

int main(void)
{
    // 1. Enable the clock for GPIOA and USART2
    RCC->AHB1ENR |= (1U << 0); // Enable GPIOA clock
    RCC->APB1ENR |= (1U << 17); // Enable USART2 clock

    // 2. Configure PA2 as Alternate Function (AF7) for USART2_TX and PA3 as AF7 for USART2_RX
    GPIOA->MODER &= ~((0x3U << (2 * 2)) | (0x3U << (3 * 2))); // Clear MODER2 and MODER3
    GPIOA->MODER |= ((0x2U << (2 * 2)) | (0x2U << (3 * 2)));  // Set MODER2 and MODER3 to AF mode
    GPIOA->AFR[0] |= ((0x7U << (4 * 2)) | (0x7U << (4 * 3))); // Set AFRL for PA2 and PA3 to AF7

    // 3. Configure USART2: Baud rate, enable RX interrupt, enable USART
    USART2->BRR = 0x0683; // Assuming 16 MHz clock, set baud rate to 9600
    USART2->CR1 |= (1U << 5); // Enable RXNE interrupt
    USART2->CR1 |= (1U << 13); // Enable USART

    // 4. Enable NVIC interrupt for USART2
    *((volatile uint32_t *)NVIC_ISER1) |= (1U << (38 - 32)); // Enable IRQ38 for USART2

    while (1)
    {
        // Main loop can process received data from the ring buffer
        // Implement processing logic here...
    }

    return 0;
}