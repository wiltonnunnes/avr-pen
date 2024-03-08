#include <avr/io.h>

void UART_init(uint16_t ubrr) {
    UBRR0L = (uint8_t)(ubrr & 0xFF);
    UBRR0H = (uint8_t)(ubrr >> 8);

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
}

int main(void) {
    DDRD |= (1 << PD2);
    DDRD &= ~(1 << PD4);

    UART_init(103);

    while (1) {
        if ((PIND & (1 << PD4)) == 0)
            PORTD &= ~(1 << PD2);
        else
            PORTD |= (1 << PD2);
    }
    return 0;
}