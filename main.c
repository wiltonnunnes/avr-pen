#include <avr/io.h>

int main(void) {
    DDRD |= (1 << PD2);
    DDRD &= ~(1 << PD4);

    while (1) {
        if ((PIND & (1 << PD4)) == 0)
            PORTD &= ~(1 << PD2);
        else
            PORTD |= (1 << PD2);
    }
    return 0;
}