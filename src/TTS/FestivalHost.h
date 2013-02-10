/*
 * FestivalHost.h
 *
 *  Created on: 25 Aug 2012
 *      Author: toby
 */

#ifndef FESTIVALHOST_H_
#define FESTIVALHOST_H_

//#include <speech_tools/EST_TIterator.h>
//#include <speech_tools/EST.h>
//#include <speech_tools/EST_cutils.h>
//#include <speech_tools/siod.h>
#include <festival/festival.h>
#include<string>

namespace TTS {

class FestivalHost {
public:
	FestivalHost();
	virtual ~FestivalHost();

	/*SoundUtil::WavSound*/void textToWav(std::string text);

private:
	const int myHeapSize;
	EST_Wave myWave;
	EST_String myString;
};

} /* namespace Festival */
#endif /* FESTIVALHOST_H_ */
