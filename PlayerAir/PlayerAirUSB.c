
#include <stdlib.h>
#include <stdio.h>

#include "PlayerAirUSB.h"
#include "PlayerAirLog.h"

PlayerAirUSB * usb = NULL;

int PlayerAirUSBInit(void)
{
	if (usb == NULL)
	{
		usb = (PlayerAirUSB*)calloc(1, sizeof(PlayerAirUSB));
		if (libusb_init(&usb->context) < 0)
		{
			PlayerAirLogCritical("fail to libusb_init(...)");
			return -1;
		}
		libusb_device** devices = NULL;
		ssize_t count = libusb_get_device_list(usb->context, &devices);
		for (ssize_t i = 0; i < count; i++)
		{
			int speed = libusb_get_device_speed(devices[i]);
			switch (speed)
			{
			case LIBUSB_SPEED_LOW:			printf("1.5M\r\n");		break;
			case LIBUSB_SPEED_FULL:			printf("12M\r\n");		break;
			case LIBUSB_SPEED_HIGH:			printf("480M\r\n");		break;
			case LIBUSB_SPEED_SUPER:		printf("5G\r\n");		break;
			case LIBUSB_SPEED_SUPER_PLUS:	printf("10G\r\n");		break;
			default:						printf("unknown\r\n");	break;
			}
			struct libusb_device_descriptor descriptor;
			libusb_device_handle* handle = NULL;
			libusb_get_device_descriptor(devices[i], &descriptor);
			printf("Dev (bus %u, device %u): %04X - %04X\n",
				libusb_get_bus_number(devices[i]), libusb_get_device_address(devices[i]),
				descriptor.idVendor, descriptor.idProduct);
			libusb_open(devices[i], &handle);
			if (handle) {
				char string[256];
				libusb_get_string_descriptor_ascii(handle, descriptor.iManufacturer, string, sizeof(string));
				printf("%s\r\n", string);
				libusb_get_string_descriptor_ascii(handle, descriptor.iProduct, string, sizeof(string));
				printf("%s\r\n", string);
				libusb_get_string_descriptor_ascii(handle, descriptor.iSerialNumber, string, sizeof(string));
				printf("%s\r\n", string);
				libusb_close(handle);
			}
		}
	}

	return 0;
}