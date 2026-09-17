// program to explain the packet parsing.
#include "stdio.h"
#include "stdint.h"

typedef struct{
    
    uint8_t header_1;
    uint8_t header_2;
    uint8_t command;
    uint8_t length;
    uint32_t data;
    
}frame_packet;

int main(void)
{
    uint8_t packet[] = {0xAA, 0x55, 0x01, 0x04, 0x10, 0x20, 0x30, 0x40};

    frame_packet *main_pkt = (frame_packet *)packet;

    printf("Header_1:0x%X\n", main_pkt->header_1);
    printf("Header_2:0x%X\n", main_pkt->header_2);
    printf("command:0x%02X\n", main_pkt->command);
    printf("length:0x%02X\n", main_pkt->length);

    uint8_t *data_main_pkt_ptr = (uint8_t *)&main_pkt->data;
    
    for(int i =0;i<4;i++)
    {
        printf("data:0x%02X\n",*data_main_pkt_ptr);
        data_main_pkt_ptr++;
    }

    return 0;
    
}

