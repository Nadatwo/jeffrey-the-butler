/*
 * FliteHost.cpp
 *
 *  Created on: 26 Aug 2012
 *      Author: toby
 */

#include "FliteHost.h"

namespace TTS {

FliteHost::FliteHost() {
	flite_init();
	myVoice = new_voice();
	myVoice = flite_voice_select("awb"); // scottish
	// TODO allow voice to be set

}

FliteHost::~FliteHost() {
	delete_voice(myVoice);
}

SoundUtil::WavSound FliteHost::textToWav(std::string text) {

	cst_wave* output = flite_text_to_wave(text.c_str(), myVoice);

	if (cst_wave_num_channels(output) != 1) {
		//convert to single channel if necessary
		cst_wave_resize(output, cst_wave_num_samples(output), 1);
	}

	SoundUtil::WavSound rValue;
	rValue.setData(cst_wave_samples(output), cst_wave_num_samples(output));
	return rValue;
}

} /* namespace TTS */
