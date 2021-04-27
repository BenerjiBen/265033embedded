#include <avr/io.h>
int main(void)
{
    DDRD |= (1<<PB1);
    DDRC &= ~(1<<PC2);
    DDRB &= ~(1<<PD1);

    PORTC |= (1<<PC2);
    PORTB |= (1<<PD1);
    while(1)
    {
        if ((PINC &(1<<PC2)) && ((PIND &(1<<PD1))))
        {
            PORTB &= ~(1<<PB1);
        }
        else if ((!(PINC &(1<<PC2))) && (PINB &(1<<PD1)))
        {
            PORTB &= ~(1<<PB1);
        }
         else if ((!(PINC &(1<<PC2))) && (!(PIND &(1<<PD1))))
        {
            PORTB |= (1<<PB1);
        }
        else if ((PINC &(1<<PC2)) && (!(PIND &(1<<PD1))))
        {
            PORTB &= ~(1<<PB1);
        }



    }
    return 0;
}
