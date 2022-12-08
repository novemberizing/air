#include <stdlib.h>

#include "PlayerAirFFMpeg.h"

PlayerAirFFMpeg * ffmpeg = NULL;

extern int PlayerAirFFMpegInit(void)
{
	if (ffmpeg == NULL)
	{
		ffmpeg = (PlayerAirFFMpeg *) calloc(1, sizeof(PlayerAirFFMpeg));
		

		ffmpeg->formatContext = avformat_alloc_context();

		if (avformat_open_input(&ffmpeg->formatContext, "pipe:", NULL, &ffmpeg->formatOptionMap) < 0)
		{
			printf("fail to avformat_open_input\r\n");
			return -1;
		}

		if (avformat_find_stream_info(ffmpeg->formatContext, &ffmpeg->formatOptionMap) < 0)
		{
			printf("fail to avformat_find_stream_info\r\n");
			return -1;
		}

		for (unsigned int i = 0; i < ffmpeg->formatContext->nb_streams; i++)
		{
			if (ffmpeg->formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
			{
				ffmpeg->parameters = ffmpeg->formatContext->streams[i]->codecpar;
				ffmpeg->codec = avcodec_find_decoder(ffmpeg->parameters->codec_id);
				break;
			}
		}

		if (!ffmpeg->parameters || !ffmpeg->codec)
		{
			printf("not found video\r\n");
			return -1;
		}

		ffmpeg->codecContext = avcodec_alloc_context3(ffmpeg->codec);

		if (avcodec_parameters_to_context(ffmpeg->codecContext, ffmpeg->parameters) < 0)
		{
			printf("fail to avcodec_parameters_to_context\r\n");
			return -1;
		}

		if (avcodec_open2(ffmpeg->codecContext, ffmpeg->codec, NULL) < 0)
		{
			printf("fail to avcodec_open2\r\n");
			return -1;
		}

		ffmpeg->frame = av_frame_alloc();
		ffmpeg->packet = av_packet_alloc();
	}

	return 0;
}

extern int PlayerAirFFMpegWidth(void)
{
	return ffmpeg && ffmpeg->parameters ? ffmpeg->parameters->width : 0;
}

extern int PlayerAirFFMpegHeight(void)
{
	return ffmpeg && ffmpeg->parameters ? ffmpeg->parameters->height : 0;
}

extern int PlayerAirFFMpegUpdateFrame(void)
{
	if (av_read_frame(ffmpeg->formatContext, ffmpeg->packet) < 0)
	{
		printf("fail to av_read_frame\r\n");
		return -1;
	}

	if (avcodec_send_packet(ffmpeg->codecContext, ffmpeg->packet) < 0)
	{
		printf("fail to send packet\r\n");
		return -1;
	}
	int ret = avcodec_receive_frame(ffmpeg->codecContext, ffmpeg->frame);
	if (ret < 0)
	{
		printf("fail to receive frame => %d\r\n", ret);
		// printf("fail to receive frame\r\n");
		return -1;
	}
	return 0;
}