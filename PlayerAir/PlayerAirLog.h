#ifndef   __NOVEMBERIZING_PLAYER_AIR__LOG__H__
#define   __NOVEMBERIZING_PLAYER_AIR__LOG__H__

#include <stdint.h>

struct PlayerAirLog;

typedef struct PlayerAirLog PlayerAirLog;

struct PlayerAirLog
{
	int32_t flags;
};

extern PlayerAirLog _log;

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

