/*
 * OggSound.cpp
 *
 *  Created on: 27 Aug 2012
 *      Author: toby
 */

#include "OggSound.h"

#include <vorbis/vorbisenc.h>

namespace SoundUtil {

OggSound::OggSound():
	myVBlockSize(1024) {

	mySerial++;

	// OGG init
	ogg_stream_init(myOStreamState, mySerial);

	// Vorbis init

	vorbis_info_init(myVInfo);

	vorbis_encode_init_vbr(myVInfo, 1, 44100, .4);

	vorbis_analysis_init(myVdspState, myVInfo);

	vorbis_comment_init(myVComment);
	// TODO don't assume metadata - we want to stream music too eventually
	vorbis_comment_add(myVComment, "ARTIST=Jeffrey");
	vorbis_comment_add(myVComment, "TITLE=Speech");

	ogg_packet* packet0 = new ogg_packet;
	ogg_packet* packet1 = new ogg_packet;
	ogg_packet* packet2 = new ogg_packet;

	myOPackets.push_back(packet0);
	myOPackets.push_back(packet1);
	myOPackets.push_back(packet2);

	vorbis_analysis_headerout(myVdspState, myVComment, myOPackets.at(0), myOPackets.at(1), myOPackets.at(2));

	vorbis_block_init(myVdspState, myVBlock);

}

OggSound::~OggSound() {

	// Vorbis uninit

	for (unsigned int i = 0; i < myOPackets.size(); i++) {
		delete myOPackets.at(i);
		myOPackets.at(i) = 0;
	}

	vorbis_block_clear(myVBlock);
	vorbis_comment_clear(myVComment);
	vorbis_dsp_clear(myVdspState);
	vorbis_info_clear(myVInfo);

	// Ogg uninit

	for (unsigned int i = 0; i < myOPages.size(); i++) {
		delete myOPages.at(i);
		myOPages.at(i) = 0;
	}

	ogg_stream_destroy(myOStreamState);
}

std::vector<ogg_packet*> OggSound::encode(WavSound& wavSound) {

	for (int i = 0; i < wavSound.getLength(); i += myVBlockSize) {
		int samplesLeft = wavSound.getLength() - (i * myVBlockSize);

		int samplesToAnalyse = myVBlockSize;

		if (samplesLeft < myVBlockSize) {
			samplesToAnalyse = samplesLeft;
		}

		float** values = vorbis_analysis_buffer(myVdspState, samplesToAnalyse);

		for (int j = 0; j < samplesToAnalyse; j++) {
			values[0][j] = (float)wavSound.getData()[(myVBlockSize * i) + j];
		}

		vorbis_analysis_wrote(myVdspState, samplesToAnalyse);

		while (vorbis_analysis_blockout(myVdspState, myVBlock)) {
			vorbis_analysis(myVBlock, NULL);
			vorbis_bitrate_addblock(myVBlock);

			ogg_packet* packetX = new ogg_packet;
			while (vorbis_bitrate_flushpacket(myVdspState, packetX)) {
				myOPackets.push_back(packetX);
				packetX = new ogg_packet;
			}
			delete packetX;

		}
	}

	vorbis_analysis_wrote(myVdspState, 0);

	while (vorbis_analysis_blockout(myVdspState, myVBlock)) {
		vorbis_analysis(myVBlock, NULL);
		vorbis_bitrate_addblock(myVBlock);

		ogg_packet* packetX = new ogg_packet;
		while (vorbis_bitrate_flushpacket(myVdspState, packetX)) {
			myOPackets.push_back(packetX);
			packetX = new ogg_packet;
		}
		delete packetX;
	}

	return myOPackets;
}

std::vector<ogg_page*> OggSound::package() {

	for (unsigned int i = 0; i < myOPackets.size(); i++) {
		ogg_stream_packetin(myOStreamState, myOPackets.at(i));
	}

	ogg_page* tempPage = new ogg_page;

	while (ogg_stream_pageout(myOStreamState, tempPage)) {
		myOPages.push_back(tempPage);
		tempPage = new ogg_page;
	}

	ogg_stream_flush(myOStreamState, tempPage);

	myOPages.push_back(tempPage);

	delete tempPage;

	return myOPages;
}

} /* namespace SoundUtil */
