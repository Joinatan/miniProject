#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdint.h>

void delay(int);
uint8_t spi_send_recv(uint8_t);
void display_init();
/* void display_update2(); */
void display_update();
void display_main();
void display_image(int x, const uint8_t *data);

#endif
