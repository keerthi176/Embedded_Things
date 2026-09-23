// C program to demonstrate the use of function pointers in a structure for different drivers (UART and SPI).

#include <stdio.h>

void uart_init(void)
{
    printf("UART Init\n");
}

void uart_send(unsigned char data)
{
    printf("UART Send: 0x%02X\n", data);
}

void spi_init(void)
{
    printf("SPI Init\n");
}

void spi_send(unsigned char data)
{
    printf("SPI Send: 0x%02X\n", data);
}

typedef struct
{
    void (*init)(void);
    void (*send)(unsigned char data);
} Driver;

int main(void)
{
    Driver uart_driver =
    {
        uart_init,
        uart_send
    };

    Driver spi_driver =
    {
        spi_init,
        spi_send
    };

    Driver *driver;

    driver = &uart_driver;

    driver->init();
    driver->send(0x55);

    driver = &spi_driver;

    driver->init();
    driver->send(0xAA);

    return 0;
}