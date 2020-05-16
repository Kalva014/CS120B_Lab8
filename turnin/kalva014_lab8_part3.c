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

    min = 0x118; //0100011000
    max = 0x27E; //1001111110

    while (1) {	
	ADC_tmp = ADC;
	
	//tmpB = (char)ADC_tmp; //Gets first 8 bits 
	//tmpD = (char)(ADC_tmp >> 8); //Get last 2 bits
	
	if(ADC_tmp >= (max / 2)) {
		PORTD = 0x01;
	}
	else if (ADC_tmp < (max / 2)) {
		PORTD = 0x00;
	}

	//PORTB = tmpB;
	//PORTD = tmpD;
    }
    return 1;
}
