/*
 * Copyright (C) eSrijan Innovations Private Limited
 * 
 * Author: Anil Kumar Pugalia <anil_pugalia@eSrijan.com>
 *
 * Licensed under: JSL (See LICENSE file for details)
 *
 * ATmega16/32
 * 
 * Toggles on & off a fan through a switch, and accordingly show its status on
 * an LED.
 * Every valid (debounced) switch press (switch input from low -> high @ PB2),
 * toggles dc motor (with fan)'s '+' pin state through PC0 - other end of the
 * dc motor being assumed to be connected to ground.
 * Same state is also output to led @ PB7
 */

#include <avr/io.h>
#include <util/delay.h>

void init_io(void)
{
	// 1 = output, 0 = input
	DDRB |= 0b10000000;
	DDRC |= 0b00000001;
}

int main(void)
{
	int can_change_state = 1;
	int state = 0;
	init_io();

	while (1)
	{
		if (can_change_state && (PINB & (1 << 2)))
		{
			_delay_ms(20);
			if (PINB & (1 << 2)) // debouncing check
			{
				state = !state;
				if (state)
				{
					PORTB |= (1 << 7);
					PORTC |= (1 << 7);
				}
				else
				{
					PORTB &= ~(1 << 7);
					PORTC &= ~(1 << 7);
				}
				can_change_state = 0;
			}
		}
		else
		{
			_delay_ms(20);
			if (!(PINB & (1 << 2))) // debouncing check
			{
				can_change_state = 1;
			}
		}
	}

	return 0;
}
