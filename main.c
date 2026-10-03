/*
 * Timer0_Normal Mode.c
 *
 * Created: 01-Oct-26 12:12:52 PM
 * Author : mziya
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
void timer0_1sec_delay()
{
	/* Configuring into normal mode */
	TCCR0A &= ~((1 << WGM00)|(1 << WGM01));
	
	/* Configuring No prescaler Mode */
	TCCR0B &= ~((1 << CS02)|(1 << CS01));
	TCCR0B |= (1 << CS00);
	
	/* Load initial Value to TCNTO; */
	TCNT0 = 0;
	
	/* Calculation............
	Timer clock = 16 MHz
	1. One timer tick = 1 / 16,000,000
	= 62.5 ns

	256 ticks = 16 ms
	
	ie,one over flow occures in every 16 ms
	
	2.How many overflow required to make one second.
	1 sec = 1000 ms = 1000000/16 = 62500
	
	*/
	for(uint16_t i=0; i<62,500; i++)
	{
		/*Wait until the overflow flag is set*/
		while(!(TIFR0 &(1 << TOV0)))
		/* Clear over flow flag in TOV0 by writing logic 1 to it. */
		TIFR0 |= (1 << TOV0);
	}
}
	int main(void)
{
    /* Configuring PORTB PIN2 as output */
	DDRB |= (1<<DDB2);
    while (1) 
    {
		/* Making pin B2 High */
		PORTB |= (1 << PORTB2);
		timer0_1sec_delay();
		/* Making pin B2 low */
		PORTB &= ~(1 << PORTB2);
		timer0_1sec_delay();
    }
}

