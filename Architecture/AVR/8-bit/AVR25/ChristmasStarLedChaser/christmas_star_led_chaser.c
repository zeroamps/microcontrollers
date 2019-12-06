#include <avr/io.h>
#include <util/delay.h>

void mode_0(void);
void mode_1(void);
void mode_2(void);
void mode_3(void);

int main(void)
{
    DDRB = _BV(PB0) | _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB4);

    while (1) {
        mode_0();
        mode_1();
        mode_0();
        mode_2();
        mode_0();
        mode_3();
    }

    return 0;
}

void mode_0(void)
{
    for (int i = 0; i < 5; i++) {
        PORTB = _BV(i);
        _delay_ms(1000);
    }

    PORTB = 0;
}

void mode_1(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            PORTB |= _BV(j);
            _delay_ms(100);
        }

        for (int j = 0; j < 5; j++) {
            PORTB &= ~(_BV(j));
            _delay_ms(100);
        }
    }
}

void mode_2(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            PORTB = _BV(j);
            _delay_ms(100);
        }
    }

    PORTB = 0;
}

void mode_3(void)
{
    for (int i = 0; i < 3; i++) {
        _delay_ms(100);
        PORTB = _BV(PB0) | _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB4);
        _delay_ms(100);
        PORTB = 0;
    }

    _delay_ms(100);
}