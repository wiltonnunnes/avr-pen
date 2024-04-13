#include <avr/io.h>
#define FOSC 16000000
#define BDIV ( FOSC / 100000 - 16) / 2 + 1

void twi_init() {
    TWSR = 0;
    TWBR = BDIV;
}