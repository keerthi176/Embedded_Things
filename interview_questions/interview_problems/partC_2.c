/*

    Question2: EXTI Push-Button Interrupt Handler Problem: The Nucleo blue user button (B1) is connected to PC13. 
    Configure PC13 as an external interrupt (EXTI13) triggered on the falling edge (button press connects pin to GND). 
    Write the Interrupt Service Routine (ISR) using function pointers to toggle LD2 (PA5) whenever the button is pressed.

*/

#include <stdint.h>

typedef struct
{
    volatile uint32_t CR;          // 0x00
    volatile uint32_t CFGR;        // 0x04
    volatile uint32_t CIR;         // 0x08
    volatile uint32_t APB2RSTR;    // 0x0C
    volatile uint32_t APB1RSTR;    // 0x10
    volatile uint32_t AHBENR;      // 0x14
    volatile uint32_t APB2ENR;     // 0x18
    volatile uint32_t APB1ENR;     // 0x1C
} RCC;

typedef struct
{
    volatile uint32_t MODER;       // 0x00
    volatile uint32_t OTYPER;      // 0x04
    volatile uint32_t OSPEEDR;     // 0x08
    volatile uint32_t PUPDR;       // 0x0C
    volatile uint32_t IDR;         // 0x10
    volatile uint32_t ODR;         // 0x14
    volatile uint32_t BSRR;        // 0x18
    volatile uint32_t LCKR;        // 0x1C
    volatile uint32_t AFR[2];      // 0x20, 0x24

} GPIO;

typedef struct
{
    volatile uint32_t CFGR1;       // 0x00
    volatile uint32_t RESERVED;    // 0x04
    volatile uint32_t EXTICR[4];   // 0x08 - 0x14
} SYSCFG;

typedef struct
{
    volatile uint32_t IMR;         // 0x00
    volatile uint32_t EMR;         // 0x04
    volatile uint32_t RTSR;        // 0x08
    volatile uint32_t FTSR;        // 0x0C
    volatile uint32_t SWIER;       // 0x10
    volatile uint32_t PR;          // 0x14
} EXTI;

#define RCC_BASE       ((RCC *)0x40021000U)

#define GPIOA          ((GPIO *)0x48000000U)
#define GPIOC          ((GPIO *)0x48000800U)

#define SYSCFG_BASE    ((SYSCFG *)0x40010000U)
#define EXTI_BASE      ((EXTI *)0x40010400U)

#define NVIC_ISER      ((volatile uint32_t *)0xE000E100U)
#define NVIC_ICPR      ((volatile uint32_t *)0xE000E280U)
#define NVIC_IPR       ((volatile uint8_t  *)0xE000E400U)

#define LED_PIN        5U
#define BUTTON_PIN     13U

#define LED_MASK       (1U << LED_PIN)
#define BUTTON_MASK    (1U << BUTTON_PIN)

#define EXTI4_15_IRQ   7U

void toggle_led(void);

void (*button_action)(void) = toggle_led;

void toggle_led(void)
{
        // LED ON
        GPIOA->ODR |= (1U << 5);

        delay(500000);

        // LED OFF
        GPIOA->ODR &= ~(1U << 5);

        delay(500000);
}

void gpio_init(void)
{
    RCC_BASE->AHBENR |= (1U << 17); // Enable GPIOA clock
    RCC_BASE->AHBENR |= (1U << 19); // Enable GPIOC

    GPIOA->MODER &= ~(3U << (LED_PIN * 2)); // Clear mode bits for PA5
    GPIOA->MODER |=  (1U << (LED_PIN * 2));

    GPIOA->OTYPER &= ~LED_MASK;
    GPIOA->OSPEEDR &= ~(3U << (LED_PIN * 2));

    GPIOA->PUPDR &= ~(3U << (LED_PIN * 2));

    GPIOA->ODR &= ~LED_MASK;
    
    GPIOC->MODER &= ~(3U << (BUTTON_PIN * 2));
    GPIOC->PUPDR &= ~(3U << (BUTTON_PIN * 2));
    GPIOC->PUPDR |=  (2U << (BUTTON_PIN * 2));
}

void EXTI_Init(void)
{
    /*
     * Enable SYSCFG peripheral clock.
     * SYSCFG clock enable = APB2ENR bit 0.
     */

    RCC_BASE->APB2ENR |= (1U << 0);

    /*
     * EXTI13 is configured through EXTICR4.
     *
     * EXTICR[3], bits 7:4 correspond to EXTI13.
     *
     * 0000 = Port A
     * 0001 = Port B
     * 0010 = Port C
     */

    SYSCFG_BASE->EXTICR[3] &= ~(0xFU << 4);

    SYSCFG_BASE->EXTICR[3] |=  (0x2U << 4);

    /*
     * Disable EXTI13 interrupt during configuration.
     */

    EXTI_BASE->IMR &= ~BUTTON_MASK;

    /*
     * Disable rising-edge trigger.
     */

    EXTI_BASE->RTSR &= ~BUTTON_MASK;

    /*
     * Enable falling-edge trigger.
     */

    EXTI_BASE->FTSR |= BUTTON_MASK;

    /*
     * Clear pending EXTI13 interrupt.
     *
     * PR bits are cleared by writing 1.
     */

    EXTI_BASE->PR = BUTTON_MASK;

    /*
     * Clear pending NVIC interrupt.
     */

    NVIC_ICPR[0] = (1U << EXTI4_15_IRQ);

    /*
     * Set interrupt priority.
     *
     * STM32F070 implements 2 priority bits.
     * Priority 1 is selected here.
     */

    NVIC_IPR[EXTI4_15_IRQ] = (1U << 6);

    /*
     * Enable EXTI4_15 interrupt in NVIC.
     */

    NVIC_ISER[0] = (1U << EXTI4_15_IRQ);

    /*
     * Enable EXTI13 interrupt.
     */

    EXTI_BASE->IMR |= BUTTON_MASK;
}

void EXTI4_15_IRQHandler(void)
{
    /*
     * Check whether EXTI13 generated the interrupt.
     */

    if (EXTI_BASE->PR & BUTTON_MASK)
    {
        /*
         * Clear EXTI13 pending flag.
         */

        EXTI_BASE->PR = BUTTON_MASK;

        /*
         * Execute the callback through
         * the function pointer.
         */

        button_action();
    }
}

int main(void)
{
    GPIO_Init();

    EXTI_Init();

    while (1)
    {
        /*
         * CPU remains here.
         *
         * LED toggles only when B1 is pressed.
         */
    }

    return 0;
}
