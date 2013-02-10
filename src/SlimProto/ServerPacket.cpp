/*
 * SlimProtoServerPacket.cpp
 *
 *  Created on: 6 Aug 2012
 *      Author: toby
 */

#include "ServerPacket.h"

namespace SlimProto {

ServerPacket::ServerPacket(uint16_t length, std::string operation):
	NetworkWrapper::Packet(0),
	myLength("Length", 2, length),
	myOperation("Operation", 4, operation) {

	setSize(length + myLength.getLength());

}

ServerPacket::~ServerPacket() {

}

void ServerPacket::setLength(uint16_t length) {
	myLength.setValue(length);
	setSize(length + myLength.getLength());
}

}
