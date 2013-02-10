/*
 * WavSound.cpp
 *
 *  Created on: 25 Aug 2012
 *      Author: toby
 */

#include "WavSound.h"

namespace SoundUtil {

WavSound::WavSound():
	myLength(0) {
	myData = new short[myLength];

}

WavSound::~WavSound() {
	delete myData;
}

void WavSound::setData(short* data, int length) {
	myLength = length;

	delete myData;
	myData = new short[myLength];

	for (int i = 0; i < myLength; i++) {
		myData[i] = data[i];
	}
}

} /* namespace SoundUtil */
