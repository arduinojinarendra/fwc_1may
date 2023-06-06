#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main(void) {
    bool f = 0;
    bool x = 0, y = 0, z = 0;
    DDRD = 0b00000100; // PD2 as output
    
    PORTD = 0b11100000; // Set internal pull-ups for PD5, PD6, PD7

    while (1) {
       

        x = (PIND & (1 << PIND5)) == (1 << PIND5);
        y = (PIND & (1 << PIND6)) == (1 << PIND6);
        z = (PIND & (1 << PIND7)) == (1 << PIND7);
        f = ((!x && !z) + (y && !z));

        PORTD = (f << 2);

        if (y) {
            PORTD |= ~(1 << PD2); // Turn on PD2 when y is 1
        } else {
            PORTD &= (1 << PD2); // Turn off PD2 when y is not 1
        }

        _delay_ms(200L);
    }

    return 0;
}

