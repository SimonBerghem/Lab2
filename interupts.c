// interuppts
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

#include "tinythreads.h"

void inter_init(void){
	PORTB = 0x80; // set joystic down to read
	EIMSK = (1 << PCIE1);
	PCMSK1 = (1 << PCINT15);
}

// joystick down interrupt
ISR(PCINT1_vect){
	if (!(PINB >> 7)){
		yield();
	}
}
