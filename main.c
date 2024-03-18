#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

void UART_init(uint16_t ubrr) {
    UBRR0L = (uint8_t)(ubrr & 0xFF);
    UBRR0H = (uint8_t)(ubrr >> 8);

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
}

void UART_putc(uint8_t data) {
    while(!(UCSR0A & (1 >> UDRE0)));

    UDR0 = data;
}

void ADC_init() {
    ADMUX = 0b01000000;
    ADCSRA = 0b10000000;
}

unsigned short ADC_read(uint8_t adc) {
    ADMUX |= adc;
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

int main(void) {
    DDRD |= (1 << PD2);
    DDRD &= ~(1 << PD4);

    UART_init(103);
    ADC_init();

    uint8_t data = 1;

    while (1) {
        if ((PIND & (1 << PD4)) == 0)
            PORTD &= ~(1 << PD2);
        else {
            PORTD |= (1 << PD2);
            //UART_putc(data);
        }
    }
    return 0;
}