#include "clock_conv.h"

#include <libopencm3/lpc43xx/scu.h>

#include <hackrf_core.h>

void clock_conv_set_filter(clock_conv_t* const clock_conv, clock_conv_filter_t filter)
{
	switch(filter) {
		case CLOCK_CONV_FILTER_1200_MHZ:
			gpio_clear(clock_conv->gpio_filta);
			gpio_clear(clock_conv->gpio_filtb);
			break;
		case CLOCK_CONV_FILTER_500_MHZ:
			gpio_set(clock_conv->gpio_filta);
			gpio_clear(clock_conv->gpio_filtb);
			break;
		case CLOCK_CONV_FILTER_160_MHZ:
			gpio_clear(clock_conv->gpio_filta);
			gpio_set(clock_conv->gpio_filtb);
			break;
		case CLOCK_CONV_FILTER_50_MHZ:
			gpio_set(clock_conv->gpio_filta);
			gpio_set(clock_conv->gpio_filtb);
			break;
	}
}

void clock_conv_set_clkin(clock_conv_t* const clock_conv, const uint_fast8_t enable)
{
	if(enable) {
		gpio_clear(clock_conv->gpio_sd1);
	} else {
		gpio_set(clock_conv->gpio_sd1);
	}
}

void clock_conv_set_aux(clock_conv_t* const clock_conv, const uint_fast8_t enable)
{
	if(enable) {
		gpio_clear(clock_conv->gpio_sd2);
	} else {
		gpio_set(clock_conv->gpio_sd2);
	}
}

void clock_conv_pin_setup(clock_conv_t* const clock_conv)
{
	scu_pinmux(SCU_PINMUX_GPIO3_8,	SCU_GPIO_FAST | SCU_CONF_FUNCTION0);
	scu_pinmux(SCU_PINMUX_GPIO3_11,	SCU_GPIO_FAST | SCU_CONF_FUNCTION0);
	scu_pinmux(SCU_PINMUX_GPIO3_12,	SCU_GPIO_FAST | SCU_CONF_FUNCTION0);
	scu_pinmux(SCU_PINMUX_GPIO3_13,	SCU_GPIO_FAST | SCU_CONF_FUNCTION0);

	// safe defaults
	clock_conv_set_filter(clock_conv, CLOCK_CONV_FILTER_50_MHZ);
	clock_conv_set_clkin(clock_conv, 0);
	clock_conv_set_aux(clock_conv, 0);

	gpio_output(clock_conv->gpio_sd1);
	gpio_output(clock_conv->gpio_sd2);
	gpio_output(clock_conv->gpio_filta);
	gpio_output(clock_conv->gpio_filtb);
}
