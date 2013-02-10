/*
 * OggSound.h
 *
 *  Created on: 27 Aug 2012
 *      Author: toby
 */

#ifndef OGGSOUND_H_
#define OGGSOUND_H_

#include <vorbis/codec.h>
#include <ogg/ogg.h>
#include <vector>
#include "WavSound.h"

namespace SoundUtil {

class OggSound {
public:
	OggSound();
	virtual ~OggSound();

	std::vector<ogg_packet*> encode(WavSound& wavSound);
	std::vector<ogg_page*> package();

	static int mySerial;

protected:

	const int myVBlockSize;
	vorbis_info* myVInfo;
	vorbis_dsp_state* myVdspState;
	vorbis_comment* myVComment;
	vorbis_block* myVBlock;

	ogg_stream_state* myOStreamState;
	std::vector<ogg_packet*> myOPackets;
	std::vector<ogg_page*> myOPages;
};

int OggSound::mySerial = 0;

} /* namespace SoundUtil */
#endif /* OGGSOUND_H_ */
