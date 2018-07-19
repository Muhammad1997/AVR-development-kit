#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
//LED test 
//connect from b0 - b7
int main(void)
{
	DDRB = 0xff;
    while (1) 
	
    {
		PORTB = 0b11111111;
		_delay_ms(1000);
		PORTB = 0b00000000;
		_delay_ms(500);
		PORTB = 0b00000001;
		_delay_ms(500);
		PORTB = 0b00000010;
		_delay_ms(500);
		PORTB = 0b00000100;
		_delay_ms(500);
		PORTB = 0b00001000;
		_delay_ms(500);
		PORTB = 0b00010000;
		_delay_ms(500);
		PORTB = 0b00100000;
		_delay_ms(500);
		PORTB = 0b01000000;
		_delay_ms(500);
		PORTB = 0b10000000;
		_delay_ms(500);
		PORTB = 0b11000000;
		_delay_ms(500);
		PORTB = 0b11100000;
		_delay_ms(500);
		PORTB = 0b11110000;
		_delay_ms(500);
		PORTB = 0b11111000;
		_delay_ms(500);
		PORTB = 0b11111100;
		_delay_ms(500);
		PORTB = 0b11111110;
		_delay_ms(500);
		PORTB = 0b11111111;
		_delay_ms(1000);
		
    }
}

