/*
<<<<<<< HEAD
 * Timer0_CTC Mode.c
 *
 * Created: 04-Oct-26 2:21:18 PM
=======
 * Timer0_Normal Mode.c
 *
 * Created: 01-Oct-26 12:12:52 PM
>>>>>>> b2cd3ec1fa0e50955300ff3d09bc18e562bcbd82
 * Author : mziya
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
void timer0_1sec_delay()
{
<<<<<<< HEAD
	/* Configure timer0 in CTC mode */
	TCCR0A |= (1 << WGM01);
	TCCR0A &= ~(1 << WGM00);
	/* Configure the prescaler value */
	TCCR0B |= (1 << CS00 | 1 << CS01);
	
	/* Calculation....
	
	current clock frequency = 16000000/64 = 250000
	tick time = 1/250000 = 4 microseconds
	OCR0A = ((Delay*clock frequency)/N))
	delay = 1 ms
	OCR0A = 249
	
	*/
	 /* Set the compare value for 1ms delay */
	OCR0A = 249;
	/* Loop 1000 times (1ms * 1000 = 1 second) */
	for(int i=0; i<1000 ; i++)
	{

		/* waiting for OCF0A to set */
		while(!(TIFR0 & (1 << OCF0A)));
		/* Clearing the flag */
}
/* Stop the timer clock when done to save power */
TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
}


int main(void)
{
    /* configuring PORTB PIN 2 as o/p */
	DDRB |= (1 << DDB2);
    while (1) 
    {
		PORTB |= (1 << PORTB2);
		timer0_1sec_delay();
		PORTB &= ~(1 << PORTB2);
		timer0_1sec_delay();
		
=======
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

	one overflow(256 ticks) = 16 microseconds = 0.000016 seconds
	
	ie,one over flow occures in every 16 ms
	
	2.Total overflow for one second.
	1 sec = 1000 ms = 1/0.000016 = 62500
	
	*/
	for(uint16_t i=0; i<62500; i++)
	{
		/*Wait until the overflow flag is set*/
		while(!(TIFR0 &(1 << TOV0)))
		/* Clear over flow flag in TOV0 by writing logic 1 to it. */
		TIFR0 |= (1 << TOV0);
	}
	/* Turn off the timer clock when done */
	TCCR0B &= ~((1 << CS00));
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
>>>>>>> b2cd3ec1fa0e50955300ff3d09bc18e562bcbd82
    }
}

