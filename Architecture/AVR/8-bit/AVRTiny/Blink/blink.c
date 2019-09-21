#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= _BV(PB2); // turns PIN 2 as an output pin

    while (1) {
        PORTB |= _BV(PB2); // turns PIN 2 high (logic one)
        _delay_ms(1000); // waits 1000 milliseconds
        PORTB &= ~(_BV(PB2)); // turns PIN 2 low (logic zero)
        _delay_ms(1000); // waits 1000 milliseconds
    }

    return 0;
}