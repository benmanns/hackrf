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
