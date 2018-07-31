#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
//#include <avr/interrupt.h>

double dutyCycle = 0;

void InitAdc()
{
ADMUX  |= 1<< REFS0; //AREF = AVCC 
ADMUX  |= 1<< ADLAR; //enable 8-bit mode
ADCSRA |= 1<< ADPS2; //ADC Prescaler = 16 between 0-20  (1000000/50000) 
//ADCSRA |= 1<< ADIE; //enable Interrupt conversion 
ADCSRA |= 1<< ADEN; //enable adc
ADCSRA |= 1<< ADSC; //start conversion
}

void InitDac()
{
		// initialize timer2 in PWM mode
		TCCR2 |= (1<<WGM20)|(1<<COM21)|(1<<WGM21)|(1<<CS20);
		DDRD |= (1<<PD7);
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

/*void AnaloWrite(double dutyCycle){
	OCR1A = dutyCycle;
}*/

/*ISR(TIMER0_OVF_vect)
{
	AnaloWrite(dutyCycle);
}*/

int main(void)

{
	int adc_result;
	InitAdc();
	InitDac();
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
	OCR2 = adc_result;
	_delay_ms(10);  
	Lcd_Clear();
    }
}

