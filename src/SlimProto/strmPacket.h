/*
 * strmPacket.h
 *
 *  Created on: 17 Aug 2012
 *      Author: toby
 */

#ifndef STRMPACKET_H_
#define STRMPACKET_H_

#include "ServerPacket.h"

namespace SlimProto {

class strmPacket: public SlimProto::ServerPacket {
public:
	strmPacket();
	virtual ~strmPacket();

	virtual void updateBuffer();

	virtual void readBufferToFields();

	void setFields(std::string command,
			uint8_t autoStart,
			std::string formatByte,
			uint8_t pcmSampleSize,
			uint8_t pcmSampleRate,
			uint8_t pcmChannels,
			uint8_t pcmEndian,
			uint8_t threshold,
			uint8_t spdifEnable,
			uint8_t transPeriod,
			uint8_t transType,
			uint8_t flags,
			uint8_t outputThreshold,
			uint32_t replayGain,
			uint16_t serverPort,
			uint32_t serverIp,
			std::string HTTPHeader);

protected:
	NetworkWrapper::TextField myCommand;
	NetworkWrapper::NumberField myAutoStart;
	NetworkWrapper::TextField myFormatByte;
	NetworkWrapper::NumberField myPcmSampleSize;
	NetworkWrapper::NumberField myPcmSampleRate;
	NetworkWrapper::NumberField myPcmChannels;
	NetworkWrapper::NumberField myPcmEndian;
	NetworkWrapper::NumberField myThreshold;
	NetworkWrapper::NumberField mySpdifEnable;
	NetworkWrapper::NumberField myTransPeriod;
	NetworkWrapper::NumberField myTransType;
	NetworkWrapper::NumberField myFlags;
	NetworkWrapper::NumberField myOutputThreshold;
	const NetworkWrapper::NumberField myReserved;
	NetworkWrapper::NumberField myReplayGain;
	NetworkWrapper::NumberField myServerPort;
	NetworkWrapper::NumberField myServerIp;
	NetworkWrapper::TextField myHTTPHeader;
};

} /* namespace SlimProto */
#endif /* STRMPACKET_H_ */
