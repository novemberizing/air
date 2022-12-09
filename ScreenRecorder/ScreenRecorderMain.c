#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int running = 1;
	while (running)
	{
		system("adb exec-out screenrecord --bit-rate=64m --output-format=h264 --size=1080x2400 -");
	}
	
	return 0;
}