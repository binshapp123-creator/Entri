/*
 * Timer0_CTC Mode.c
 *
 * Created: 04-Oct-26 2:21:18 PM
 * Author : mziya
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
void timer0_1sec_delay()
{
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
		
    }
}

