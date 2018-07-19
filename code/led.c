#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
//7-seg test 
//connect 7-seg from D0 - D7
//connect trans C0,C1,C6,C7

char 7seg [] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void num (int i);
int i,j,k,l;
int main(void)
{
	DDRD = 0xff;
	DDRC = 0xff;
    while (1) 
	
    {	
    }
}

void num (int number){
	l = number%10;
	number = number/10;
	
	k = number%10;
	number = number/10;
	
	j = number%10;
	number = number/10;
	
	i = number%10;
	number = number/10;
	
	PORTC = 0b0000001;
	PORTD = 7seg[i];
	_delay_ms
	
}
