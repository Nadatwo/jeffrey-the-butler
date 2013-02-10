/*
 * SlimProtoClientPacket.cpp
 *
 *  Created on: 6 Aug 2012
 *      Author: toby
 */

#include "ClientPacket.h"

namespace SlimProto {

ClientPacket::ClientPacket(std::string operation, uint32_t length):
		NetworkWrapper::Packet(0),
	myOperation("Operation", 4, operation),
	myLength("Length", 4, length) {

	setSize((unsigned short)length + myOperation.getLength() + myLength.getLength());
}

ClientPacket::~ClientPacket() {

}

void ClientPacket::setLength(uint32_t length) {
	myLength.setValue(length);
	setSize(length + myOperation.getLength() + myLength.getLength());
}

}
