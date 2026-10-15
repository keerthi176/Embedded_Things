/*

    Question2: EXTI Push-Button Interrupt Handler Problem: The Nucleo blue user button (B1) is connected to PC13. 
    Configure PC13 as an external interrupt (EXTI13) triggered on the falling edge (button press connects pin to GND). 
    Write the Interrupt Service Routine (ISR) using function pointers to toggle LD2 (PA5) whenever the button is pressed.

*/

#include <stdint.h>

#define EXTI_BASE       (0x40013C00UL)
#define SYSCFG_BASE     (0x40013800UL)
#define NVIC_ISER0      (0xE000E100UL)
#define RCC_BASE        (0x40023800UL)
#define GPIOC_BASE      (0x40020800UL)
#define GPIOA_BASE      (0x40020000UL)

typedef struct {

    volatile uint32_t IMR;   // Interrupt mask register
    volatile uint32_t EMR;   // Event mask register
    volatile uint32_t RTSR;  // Rising trigger selection register
    volatile uint32_t FTSR;  // Falling trigger selection register
    volatile uint32_t SWIER; // Software interrupt event register
    volatile uint32_t PR;    // Pending register

} EXTI_TypeDef;

typedef struct {

    volatile uint32_t MEMRMP;       // Memory remap register
    volatile uint32_t PMC;          // Peripheral mode configuration register
    volatile uint32_t EXTICR[4];    // External interrupt configuration registers
    volatile uint32_t CMPCR;        // Compensation cell control register

} SYSCFG_TypeDef;

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
    volatile uint32_t APB2ENR;       // Offset 0x34: APB2 peripheral clock enable register

} RCC_TypeDef;

#define RCC             ((RCC_TypeDef *)RCC_BASE)
#define GPIOA           ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOC           ((GPIO_TypeDef *)GPIOC_BASE)
#define EXTI            ((EXTI_TypeDef *)EXTI_BASE)
#define SYSCFG          ((SYSCFG_TypeDef *)SYSCFG_BASE)

int main(void)
{
    // 1. Enable the clock for GPIOA and GPIOC in RCC_AHB1ENR
    RCC->AHB1ENR |= (1U << 0) | (1U << 2); // Enable GPIOA and GPIOC clocks

    // 2. Configure PA5 as General Purpose Output mode in GPIOA_MODER
    GPIOA->MODER &= ~(0x3U << (5 * 2)); // Clear MODER5 bits
    GPIOA->MODER |= (0x1U << (5 * 2));  // Set MODER5 to 01 (General Purpose Output)

    // 3. Configure PC13 as input with pull-up resistor
    GPIOC->MODER &= ~(0x3U << (13 * 2)); // Clear MODER13 bits (input mode)
    GPIOC->PUPDR &= ~(0x3U << (13 * 2)); // Clear PUPDR13 bits
    GPIOC->PUPDR |= (0x1U << (13 * 2));  // Set PUPDR13 to 01 (pull-up)

    // 4. Configure SYSCFG to map EXTI13 to PC13
    SYSCFG->EXTICR[3] &= ~(0xFU << ((13 - 12) * 4)); // Clear EXTICR3[1:0] for EXTI13
    SYSCFG->EXTICR[3] |= (0x2U << ((13 - 12) * 4));   // Set EXTICR3[1:0] to 0010 for PC13

    // 5. Configure EXTI13 for falling edge trigger and enable interrupt
    EXTI->FTSR |= (1U << 13);   // Falling trigger enabled for EXTI13
    EXTI->IMR |= (1U << 13);     // Unmask EXTI13 interrupt

    // 6. Enable EXTI15_10 interrupt in NVIC
    *((volatile uint32_t *)NVIC_ISER0) |= (1U << ((40 - 32))); // Enable IRQ40 for EXTI15_10

    while (1) {
        // Main loop can be empty; ISR handles button press
    }

    return 0;
}

void EXTI15_10_IRQHandler(void)
{
    // Check if EXTI13 triggered the interrupt
    if (EXTI->PR & (1U << 13)) {
        // Clear the pending bit for EXTI13
        EXTI->PR |= (1U << 13);

        // Toggle LD2 (PA5)
        GPIOA->ODR ^= (1U << 5);
    }
}