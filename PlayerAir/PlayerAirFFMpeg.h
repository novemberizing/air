#ifndef   __NOVEMBERIZING_PLAYER_AIR__FFMPEG__H__
#define   __NOVEMBERIZING_PLAYER_AIR__FFMPEG__H__

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

struct PlayerAirFFMpeg;

typedef struct PlayerAirFFMpeg PlayerAirFFMpeg;

struct PlayerAirFFMpeg
{
    AVFormatContext* formatContext;
    AVDictionary* formatOptionMap;
    AVCodecContext* codecContext;
    const AVCodec* codec;
    AVCodecParameters* parameters;
    AVFrame* frame;
    AVPacket* packet;
    struct SwsContext* swsContext;
};

extern PlayerAirFFMpeg * ffmpeg;

extern int PlayerAirFFMpegInit(void);

extern int PlayerAirFFMpegUpdateFrame(void);

extern int PlayerAirFFMpegWidth(void);
extern int PlayerAirFFMpegHeight(void);

#endif // __NOVEMBERIZING_PLAYER_AIR__FFMPEG__H__

