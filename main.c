#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << DDB4);
    while (1) {
        PORTB |= (1 << PB4);
        _delay_ms(1000);
        PORTB &= ~(1 << PB4);
        _delay_ms(1000);
    }
    return 1;
}