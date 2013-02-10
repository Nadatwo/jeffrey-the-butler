/*
 * WavSound.h
 *
 *  Created on: 25 Aug 2012
 *      Author: toby
 */

#ifndef WAVSOUND_H_
#define WAVSOUND_H_

namespace SoundUtil {

class WavSound {
public:
	WavSound();
	virtual ~WavSound();

	//make a deep copy of the given data in myData
	void setData(short* data, int length);

	const short* getData() {
		return myData;
	}

	int getLength() {
		return myLength;
	}

protected:
	short* myData;
	int myLength;
};

} /* namespace SoundUtil */
#endif /* WAVSOUND_H_ */
