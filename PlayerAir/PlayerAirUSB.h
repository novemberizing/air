#ifndef   __NOVEMBERIZING_PLAYER_AIR__USB__H__
#define   __NOVEMBERIZING_PLAYER_AIR__USB__H__

#include <libusb.h>

struct PlayerAirUSB;

typedef struct PlayerAirUSB PlayerAirUSB;

struct PlayerAirUSB
{
	libusb_context * context;
};

extern PlayerAirUSB * usb;

extern int PlayerAirUSBInit(void);

#endif // __NOVEMBERIZING_PLAYER_AIR__USB__H__
