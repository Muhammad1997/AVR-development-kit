#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
char *key;
void keypad();
int main()
{
	DDRB = 0xff;
	DDRD = 0xff;
	DDRA = 0xf0;
	PORTA = 0x0f; //enable pull up res
    while (1) 
    {
		keypad();
		
    }
}

//keypad fun
void keypad (){
	//first row
	if (!(PINA & 1<<PA0))
	{
		PORTA |= 0b00010000;
		//first col
		if (PINA & 1<<PA0)
		{
			key = "1";
			PORTB = 0b00000001;
		}
		else {
			
			PORTA &= 0b11101111;
			PORTA |= 0b00100000;
			//2nd col
			if (PINA & 1<<PA0)
			{
				key = "2";
				PORTB = 0b00000010;
			}
			else{
				PORTA &= 0b11011111;
				PORTA |= 0b01000000;
				//3rd col
				if (PINA & 1<<PA0)
				{
					key = "3";
					PORTB = 0b00000100;
				}
				//4th col
				else
				{
					PORTA &= 0b10111111;
					PORTA |= 0b10000000;
					key = "4";
					PORTB = 0b00001000;
				}
				
				
			}
		}
	}
	
	//2nd row
	else if (!(PINA & 1<<PA1))
	{
		PORTA |= 0b00010000;
		//first col
		if (PINA & 1<<PA1)
		{
			key = "5";
			PORTB = 0b00010000;
		}
		else {
			
			PORTA &= 0b11101111;
			PORTA |= 0b00100000;
			//2nd col
			if (PINA & 1<<PA1)
			{
				key = "6";
				PORTB = 0b00100000;
			}
			else{
				PORTA &= 0b11011111;
				PORTA |= 0b01000000;
				//3rd col
				if (PINA & 1<<PA1)
				{
					key = "7";
					PORTB = 0b01000000;
				}
				//4th col
				else
				{
					PORTA &= 0b10111111;
					PORTA |= 0b10000000;
					key = "8";
					PORTB = 0b10000000;
				}
				
				
			}
		}
	}
	
	//3rd row
	else if (!(PINA & 1<<PA2))
	{
		PORTA |= 0b00010000;
		//first col
		if (PINA & 1<<PA2)
		{
			key = "9";
			PORTD = 0b00000001;
		}
		else {
			
			PORTA &= 0b11101111;
			PORTA |= 0b00100000;
			//2nd col
			if (PINA & 1<<PA2)
			{
				key = "10";
				PORTD = 0b00000010;
			}
			else{
				PORTA &= 0b11011111;
				PORTA |= 0b01000000;
				//3rd col
				if (PINA & 1<<PA2)
				{
					key = "11";
					PORTD = 0b00000100;
				}
				//4th col
				else
				{
					PORTA &= 0b10111111;
					PORTA |= 0b10000000;
					key = "12";
					PORTD = 0b00001000;
				}
				
				
			}
		}
	}
	
	//4th row
	else if (!(PINA & 1<<PA3))
	{
		PORTA |= 0b00010000;
		//first col
		if (PINA & 1<<PA3)
		{
			key = "13";
			PORTD = 0b00010000;
		}
		else {
			
			PORTA &= 0b11101111;
			PORTA |= 0b00100000;
			//2nd col
			if (PINA & 1<<PA3)
			{
				key = "14";
				PORTD = 0b00100000;
			}
			else{
				PORTA &= 0b11011111;
				PORTA |= 0b01000000;
				//3rd col
				if (PINA & 1<<PA3)
				{
					key = "15";
					PORTD = 0b01000000;
				}
				//4th col
				else
				{
					PORTA &= 0b10111111;
					PORTA |= 0b10000000;
					key = "16";
					PORTD = 0b10000000;
				}
				
				
			}
		}
	}
	PORTA &= 0b00001111;
	_delay_ms(50);
	PORTB = 0b00000000;
	PORTD = 0b00000000;

}

