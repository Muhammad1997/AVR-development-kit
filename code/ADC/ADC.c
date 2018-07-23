#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>

void InitAdc()
{
ADMUX  |= 1<< REFS0; //AREF = AVCC 
ADMUX  |= 1<< ADLAR; //enable 8-bit mode
ADCSRA |= 1<< ADPS2; //ADC Prescaler = 16 between 0-20  (1000000/50000) 
//ADCSRA |= 1<< ADIE; //enable Interrupt conversion 
ADCSRA |= 1<< ADEN; //enable adc
ADCSRA |= 1<< ADSC; //start conversion
}

int AnalogRead(char ch)
{
	//Select ADC Channel ch must be 0-7
	ch = ch&0b00000111;
	ADMUX = (ADMUX & 0xF8)|ch;// clears the bottom 3 bits before ORing
	ADMUX|=ch;
	ADCSRA|=(1<<ADSC);
	while(ADCSRA & (1<<ADSC));//wait till it finish
	return(ADCH);
}

int main()

{
	 int adc_result;
	InitAdc();
	Lcd_Init ();
	Lcd_Out(0,0,"ADC print");
	_delay_ms(2000);
	Lcd_Clear();
    while (1) 
    {
	char x[3];	
	adc_result  = AnalogRead(0);
	itoa(adc_result,x,10);
	Lcd_Out(0,0,"value 0-255:");
	Lcd_Out(1,0,"value:");
	Lcd_Out(1,6,x);
	_delay_ms(50);  
	Lcd_Clear();
    }
}

