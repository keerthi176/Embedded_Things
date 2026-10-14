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
    volatile uint32_t reserved1[6];
    volatile uint32_t APB2ENR;       // Offset 0x44: APB2 peripheral clock enable register
    
} RCC_TypeDef;
