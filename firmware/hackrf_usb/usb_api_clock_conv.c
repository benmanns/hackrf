#include "usb_api_clock_conv.h"

#include <clock_conv.h>

#include "usb_endpoint.h"

usb_request_status_t usb_vendor_request_set_clock_conv_filter(
	usb_endpoint_t* const endpoint, const usb_transfer_stage_t stage)
{
	if (stage == USB_TRANSFER_STAGE_SETUP) {
		switch (endpoint->setup.value) {
			case CLOCK_CONV_FILTER_1200_MHZ:
			case CLOCK_CONV_FILTER_500_MHZ:
			case CLOCK_CONV_FILTER_160_MHZ:
			case CLOCK_CONV_FILTER_50_MHZ:
				clock_conv_set_filter(&clock_conv, endpoint->setup.value);
				usb_transfer_schedule_ack(endpoint->in);
				return USB_REQUEST_STATUS_OK;
			default:
				return USB_REQUEST_STATUS_STALL;
		}
	} else {
		return USB_REQUEST_STATUS_OK;
	}
}

usb_request_status_t usb_vendor_request_set_clock_conv_clkin_enable(
	usb_endpoint_t* const endpoint, const usb_transfer_stage_t stage)
{
	if (stage == USB_TRANSFER_STAGE_SETUP) {
		switch (endpoint->setup.value) {
		case 0:
			clock_conv_set_clkin(&clock_conv, 0);
			usb_transfer_schedule_ack(endpoint->in);
			return USB_REQUEST_STATUS_OK;
		case 1:
			clock_conv_set_clkin(&clock_conv, 1);
			usb_transfer_schedule_ack(endpoint->in);
			return USB_REQUEST_STATUS_OK;
		default:
			return USB_REQUEST_STATUS_STALL;
		}
	} else {
		return USB_REQUEST_STATUS_OK;
	}
}

usb_request_status_t usb_vendor_request_set_clock_conv_aux_enable(
	usb_endpoint_t* const endpoint, const usb_transfer_stage_t stage)
{
	if (stage == USB_TRANSFER_STAGE_SETUP) {
		switch (endpoint->setup.value) {
		case 0:
			clock_conv_set_aux(&clock_conv, 0);
			usb_transfer_schedule_ack(endpoint->in);
			return USB_REQUEST_STATUS_OK;
		case 1:
			clock_conv_set_aux(&clock_conv, 1);
			usb_transfer_schedule_ack(endpoint->in);
			return USB_REQUEST_STATUS_OK;
		default:
			return USB_REQUEST_STATUS_STALL;
		}
	} else {
		return USB_REQUEST_STATUS_OK;
	}
}
