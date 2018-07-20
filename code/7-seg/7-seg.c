#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>

char array[]={0b01000000,0b01111001,0b00100100,0b00110000,0b00011001,0b00010010,0b00000010,0b01111000,0b00000000,0b00010000};
char i,j;

void SevenSeg_SetNumber(int num)
{
	j=num%10;
	num = num/10;
	
	i=num%10;
	num = num/10;
}

void seven_seg(int num){
	SevenSeg_SetNumber(num);
	PORTB = array[i];
	PORTD = 0b00000001;
	_delay_ms(10);
	PORTB = array[j];
	PORTD = 0b00000010;
	_delay_ms(10);
	
}

int main (){
	PORTD = 0xff;
	DDRB = 0xff;
	while (1)
	{
		seven_seg(20);
	}
	
	
}

