/*
 * SlimProtoPacket.cpp
 *
 *  Created on: 6 Aug 2012
 *      Author: toby
 */

#include "Packet.h"
#include <sstream>

namespace NetworkWrapper {

Packet::Packet(short size):
	mySize(0),
	myBuffer(0) {

	setSize(size);
}

Packet::~Packet() {
	delete myBuffer;
	myBuffer = 0;
}

void Packet::setSize(unsigned short size) {
	delete[] myBuffer;
	myBuffer = new uint8_t[size];
	mySize = size;
}

void Packet::updateBuffer() {
	for (unsigned short i = 0; i < mySize; i++) {
		myBuffer[i] = 0;
	}
}

void Packet::readBufferToFields() {

}

std::string Packet::toString() {
	std::string rValue = "";

	for (short i = 0; i < getSize(); i++) {
		rValue.append((char*)(myBuffer + i));
	}

	return rValue;
}

uint8_t* Packet::updateBufferHelper(uint8_t* buffer, Field data) {
	// TODO make this more efficient - this calls getLength and getValue more than necessary

	for (unsigned short i = 0; i < data.getLength(); i++) {
			buffer[i] = data.getValue()[i];
		}

	return buffer + data.getLength();
}

uint8_t* Packet::readBufferToFieldsHelper(uint8_t* buffer, Field data) {
	// TODO make this more efficient - this calls getLength and getValue more than necessary

	uint8_t value[data.getLength()];

	for (unsigned short i = 0; i < data.getLength(); i++) {
			value[i] = buffer[i];
		}

	data.setValue(value);

	return buffer + data.getLength();
}

}
