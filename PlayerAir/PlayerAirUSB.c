
#include <stdlib.h>

#include "PlayerAirUSB.h"
#include "PlayerAirLog.h"

PlayerAirUSB * usb = NULL;

int PlayerAirUSBInit(void)
{
	if (usb == NULL)
	{
		usb = (PlayerAirUSB*)calloc(1, sizeof(PlayerAirUSB));
		/*
		if (libusb_init(&usb->context) < 0)
		{
			PlayerAirLogCritical("fail to libusb_init(...)");
			return -1;
		}
		*/
	}

	return 0;
}