/*
 * strmPacket.cpp
 *
 *  Created on: 17 Aug 2012
 *      Author: toby
 */

#include "strmPacket.h"

namespace SlimProto {

strmPacket::strmPacket():
	ServerPacket(24, "strm"),
	myCommand("Command", 1),
	myAutoStart("AutoStart", 1),
	myFormatByte("Format Byte", 1),
	myPcmSampleSize("PCM Sample Size", 1),
	myPcmSampleRate("PCM Sample Rate", 1),
	myPcmChannels("PCM Channels", 1),
	myPcmEndian("PCM Endian", 1),
	myThreshold("Threshold", 1),
	mySpdifEnable("SPDIF Enable", 1),
	myTransPeriod("Transition Period", 1),
	myTransType("Transition Type", 1),
	myFlags("Flags", 1),
	myOutputThreshold("Output Threshold", 1),
	myReserved("RESERVED", 1, 0),
	myReplayGain("Replay Gain", 4),
	myServerPort("Server Port", 2),
	myServerIp("Server IP", 4),
	myHTTPHeader("HTTP Header", 0)
	{
	// TODO Auto-generated constructor stub

}

strmPacket::~strmPacket() {
	// TODO Auto-generated destructor stub
}

void strmPacket::updateBuffer() {
	uint8_t* workingBuffer = myBuffer;

	workingBuffer = updateBufferHelper(workingBuffer, myLength);
	workingBuffer = updateBufferHelper(workingBuffer, myOperation);
	workingBuffer = updateBufferHelper(workingBuffer, myCommand);
	workingBuffer = updateBufferHelper(workingBuffer, myAutoStart);
	workingBuffer = updateBufferHelper(workingBuffer, myFormatByte);
	workingBuffer = updateBufferHelper(workingBuffer, myPcmSampleSize);
	workingBuffer = updateBufferHelper(workingBuffer, myPcmSampleRate);
	workingBuffer = updateBufferHelper(workingBuffer, myPcmChannels);
	workingBuffer = updateBufferHelper(workingBuffer, myPcmEndian);
	workingBuffer = updateBufferHelper(workingBuffer, myThreshold);
	workingBuffer = updateBufferHelper(workingBuffer, mySpdifEnable);
	workingBuffer = updateBufferHelper(workingBuffer, myTransPeriod);
	workingBuffer = updateBufferHelper(workingBuffer, myTransType);
	workingBuffer = updateBufferHelper(workingBuffer, myFlags);
	workingBuffer = updateBufferHelper(workingBuffer, myOutputThreshold);
	workingBuffer = updateBufferHelper(workingBuffer, myReserved);
	workingBuffer = updateBufferHelper(workingBuffer, myReplayGain);
	workingBuffer = updateBufferHelper(workingBuffer, myServerPort);
	workingBuffer = updateBufferHelper(workingBuffer, myServerIp);
	workingBuffer = updateBufferHelper(workingBuffer, myHTTPHeader);
}

void strmPacket::readBufferToFields() {
	uint8_t* workingBuffer = myBuffer;

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myLength);

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myOperation);

	if (myOperation != "strm") {
		throw(PacketOperationMismatch());
	}

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myCommand);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myAutoStart);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myFormatByte);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myPcmSampleSize);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myPcmSampleRate);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myPcmChannels);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myPcmEndian);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myThreshold);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, mySpdifEnable);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myTransPeriod);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myTransType);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myFlags);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myOutputThreshold);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myReplayGain);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myServerPort);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myServerIp);
	workingBuffer = readBufferToFieldsHelper(workingBuffer, myHTTPHeader);

}

void strmPacket::setFields(std::string command,
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
		std::string HTTPHeader) {
	myCommand.setValue(command);
	myAutoStart.setValue(autoStart);
	myFormatByte.setValue(formatByte);
	myPcmSampleSize.setValue(pcmSampleSize);
	myPcmSampleRate.setValue(pcmSampleRate);
	myPcmChannels.setValue(pcmChannels);
	myPcmEndian.setValue(pcmEndian);
	myThreshold.setValue(threshold);
	mySpdifEnable.setValue(spdifEnable);
	myTransPeriod.setValue(transPeriod);
	myTransType.setValue(transType);
	myFlags.setValue(flags);
	myOutputThreshold.setValue(outputThreshold);
	myReplayGain.setValue(replayGain);
	myServerPort.setValue(serverPort);
	myServerIp.setValue(serverIp);

	myHTTPHeader.setActive(false);
	myHTTPHeader.setLength(HTTPHeader.length());
	myHTTPHeader.setActive(true);
	myHTTPHeader.setValue(HTTPHeader);

	setLength(24 + HTTPHeader.length());

	updateBuffer();
}

} /* namespace SlimProto */
