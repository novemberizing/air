#ifndef   __NOVEMBERIZING_PLAYER_AIR__LOG__H__
#define   __NOVEMBERIZING_PLAYER_AIR__LOG__H__

#include <stdint.h>

#define PlayerAirLogFlagFunction	(0x00000001U <<	 0U)
#define PlayerAirLogFlagCritical	(0x00000001U <<  1U)
#define PlayerAirLogFlagError		(0x00000001U <<  2U)
#define PlayerAirLogFlagWarning		(0x00000001U <<  3U)
#define PlayerAirLogFlagCaution		(0x00000001U <<  4U)
#define PlayerAirLogFlagNotice		(0x00000001U <<  5U)
#define PlayerAirLogFlagInformation	(0x00000001U <<  6U)
#define PlayerAirLogFlagDebug		(0x00000001U <<  7U)
#define PlayerAirLogFlagVerbose		(0x00000001U <<  8U)

struct PlayerAirLog;

typedef struct PlayerAirLog PlayerAirLog;

struct PlayerAirLog
{
	uint32_t flags;
};

extern PlayerAirLog logger;

extern void PlayerAirLogWrite(const char * file, int line, const char * func, const char * format, ...);

#define PlayerAirLogFunctionStart(format, ...)	do {								\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#define PlayerAirLogFunctionEnd(format, ...)	do {								\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#define PlayerAirLogCritical(format, ...)	do {									\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#define PlayerAirLogError(format, ...)	do {										\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#define PlayerAirLogWarning(format, ...)	do {									\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#define PlayerAirLogCaution(format, ...)	do {									\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#define PlayerAirLogNotice(format, ...)	do {										\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#define PlayerAirLogInformation(format, ...)	do {								\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#define PlayerAirLogDebug(format, ...)	do {										\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#define PlayerAirLogVerbose(format, ...)	do {									\
	PlayerAirLogWrite(__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__);		\
} while(0)

#endif // __NOVEMBERIZING_PLAYER_AIR__LOG__H__

