/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #3
 *	Exercise Description: Turn LED on if enough light is detected
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short ADC_tmp;
unsigned char tmpB;
unsigned char tmpD;
unsigned short min;
unsigned short max;

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	
    /* Insert your solution below */
    ADC_init();

    max = 0xFF; //new max cause the amount of light changed

    while (1) {	
	ADC_tmp = ADC;	

	//tmpB = (char)ADC_tmp; //Gets first 8 bits 
	//tmpD = (char)(ADC_tmp >> 8); //Get last 2 bits
	
	if(ADC_tmp >= (max / 8)) {
		tmpB = 0x01;
	}
	if(ADC_tmp >= (max / 7)) {
		tmpB = 0x03;
	}
	if(ADC_tmp >= (max / 6)) {
		tmpB = 0x07;
	}
	if(ADC_tmp >= (max / 5)) {
                tmpB = 0x0F;
        }
	if(ADC_tmp >= (max / 4)) {
                tmpB = 0x1F;
        }
	if(ADC_tmp >= (max / 3)) {
		tmpB = 0x3F;
	}
	if(ADC_tmp >= (max / 2)) {
                tmpB = 0x7F;
        }
	

	PORTB = tmpB;
	//PORTD = tmpD;
    }
    return 1;
}
