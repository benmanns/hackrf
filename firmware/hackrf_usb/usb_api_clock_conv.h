#ifndef __USB_API_CLOCK_CONV_H__
#define __USB_API_CLOCK_CONV_H__

#include <hackrf_core.h>
#include <usb_type.h>
#include <usb_request.h>

usb_request_status_t usb_vendor_request_set_clock_conv_filter(
	usb_endpoint_t* const endpoint, const usb_transfer_stage_t stage);
usb_request_status_t usb_vendor_request_set_clock_conv_clkin_enable(
	usb_endpoint_t* const endpoint, const usb_transfer_stage_t stage);
usb_request_status_t usb_vendor_request_set_clock_conv_aux_enable(
	usb_endpoint_t* const endpoint, const usb_transfer_stage_t stage);

#endif
