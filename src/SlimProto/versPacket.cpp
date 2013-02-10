/*
 * strmPacket.cpp
 *
 *  Created on: 17 Aug 2012
 *      Author: toby
 */

#include "versPacket.h"

namespace SlimProto {

versPacket::versPacket():
	ServerPacket(4, "vers"),
	myServerVersion("Server Version", 0)
	{
	// TODO Auto-generated constructor stub

}

versPacket::~versPacket() {
	// TODO Auto-generated destructor stub
}

void versPacket::updateBuffer() {
	uint8_t* workingBuffer = myBuffer;

	workingBuffer = updateBufferHelper(workingBuffer, myLength);
	workingBuffer = updateBufferHelper(workingBuffer, myOperation);
	workingBuffer = updateBufferHelper(workingBuffer, myServerVersion);
}

void versPacket::readBufferToFields() {
	uint8_t* workingBuffer = myBuffer;

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myLength);

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myOperation);

	if (myOperation != "vers") {
		throw(PacketOperationMismatch());
	}

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myServerVersion);

}

void versPacket::setFields(std::string serverVersion) {
	myServerVersion.setActive(false);
	myServerVersion.setLength(serverVersion.length());
	myServerVersion.setActive(true);
	myServerVersion.setValue(serverVersion);

	setLength(4 + serverVersion.length());

	updateBuffer();
}

} /* namespace SlimProto */
