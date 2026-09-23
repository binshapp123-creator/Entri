/*
 * GccApplication1.c
 *
 * Created: 22-Sep-26 5:47:17 PM
 * Author : mziya
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB |= (1<<DDB5);
    while (1) 
    {
		PORTB |= (1<<PORTB5);
		_delay_ms(1000);
		PORTB &= ~(1<<PORTB5);
		_delay_ms(1000);
    }
}

