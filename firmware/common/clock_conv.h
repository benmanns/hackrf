/*
 * Copyright 2021 Tomaz Solc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __CLOCKCONV_H__
#define __CLOCKCONV_H__

#include <stdint.h>

#include "gpio.h"

typedef enum {
	CLOCK_CONV_FILTER_1200_MHZ = 0,
	CLOCK_CONV_FILTER_500_MHZ = 1,
	CLOCK_CONV_FILTER_160_MHZ = 2,
	CLOCK_CONV_FILTER_50_MHZ = 3,
} clock_conv_filter_t;

typedef struct clock_conv_t {
	gpio_t gpio_sd1;
	gpio_t gpio_sd2;
	gpio_t gpio_filta;
	gpio_t gpio_filtb;
} clock_conv_t;

void clock_conv_pin_setup(clock_conv_t* const clock_conv);

void clock_conv_set_filter(clock_conv_t* const clock_conv, clock_conv_filter_t filter);
void clock_conv_set_clkin(clock_conv_t* const clock_conv, const uint_fast8_t enable);
void clock_conv_set_aux(clock_conv_t* const clock_conv, const uint_fast8_t enable);

#endif
