/*
 * Copyright (C) eSrijan Innovations Private Limited
 * 
 * Author: Anil Kumar Pugalia <anil_pugalia@eSrijan.com>
 *
 * Licensed under: JSL (See LICENSE file for details)
 *
 * Header for Common Functions for ATmega48/88/168, ATmega16/32
 */

#ifndef COMMON_H
#define COMMON_H

#include <avr/io.h>

extern void delay_us(uint16_t usecs);
extern void delay_ms(uint16_t msecs);
#endif
