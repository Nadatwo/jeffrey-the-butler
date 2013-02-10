/*
 * grfbPacket.cpp
 *
 *  Created on: 06 Jan 2013
 *      Author: toby
 */

#include "grfbPacket.h"

namespace SlimProto {

grfbPacket::grfbPacket():
	ServerPacket(6, "grfb"),
	myBrightness("Brightness", 2)
	{
	// TODO Auto-generated constructor stub

}

grfbPacket::~grfbPacket() {
	// TODO Auto-generated destructor stub
}

void grfbPacket::updateBuffer() {
	uint8_t* workingBuffer = myBuffer;

	workingBuffer = updateBufferHelper(workingBuffer, myLength);
	workingBuffer = updateBufferHelper(workingBuffer, myOperation);
	workingBuffer = updateBufferHelper(workingBuffer, myBrightness);
}

void grfbPacket::readBufferToFields() {
	uint8_t* workingBuffer = myBuffer;

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myLength);

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myOperation);

	if (myOperation != "grfb") {
		throw(PacketOperationMismatch());
	}

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myBrightness);

}

void grfbPacket::setFields(uint16_t brightness) {

	myBrightness.setValue(brightness);

	updateBuffer();
}

} /* namespace SlimProto */
