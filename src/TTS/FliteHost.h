/*
 * FliteHost.h
 *
 *  Created on: 26 Aug 2012
 *      Author: toby
 */

#ifndef FLITEHOST_H_
#define FLITEHOST_H_

#include <flite/flite.h>
#include <string>
#include "../SoundUtil/WavSound.h"

namespace TTS {

class FliteHost {
public:
	FliteHost();
	virtual ~FliteHost();

	SoundUtil::WavSound textToWav(std::string text);

private:
	cst_voice* myVoice;
};

} /* namespace TTS */
#endif /* FLITEHOST_H_ */
