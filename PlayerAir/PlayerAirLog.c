#include <stdio.h>
#include <stdarg.h>

#include "PlayerAirLog.h"

PlayerAirLog _log;

extern void PlayerAirLogWrite(const char* file, int line, const char* func, const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	printf("[%s:%d/%s] ", file, line, func);
	vprintf(format, ap);
	printf("\r\n");
	va_end(ap);
}