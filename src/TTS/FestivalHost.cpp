/*
 * FestivalHost.cpp
 *
 *  Created on: 25 Aug 2012
 *      Author: toby
 */

#include "FestivalHost.h"

namespace TTS {

FestivalHost::FestivalHost():
	myHeapSize(210000) {

	festival_initialize(true, myHeapSize);

}

FestivalHost::~FestivalHost() {
	festival_tidy_up();
}

/*SoundUtil::WavSound*/void FestivalHost::textToWav(std::string text) {

	myString = text.c_str();

	const EST_String& myESTString = myString;

	//festival_text_to_wave("Test", myWave);
	// TODO throw error - festival not supported until it compiles

	int waveChannels = myWave.num_channels();

	if (waveChannels >= 1) {
		for (int i = 0; i < myWave.length(); i += waveChannels) {
			/*wavSound = */myWave(i, 0);
		}
	} else {
		// TODO throw exception
	}
}

} /* namespace Festival */
