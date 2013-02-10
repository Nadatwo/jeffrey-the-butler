/*
 * SlimProtoServerPacket.h
 *
 *  Created on: 6 Aug 2012
 *      Author: toby
 */

#ifndef SERVERPACKET_H_
#define SERVERPACKET_H_

#include "../NetworkWrapper/Packet.h"
#include "../NetworkWrapper/NumberField.h"
#include "../NetworkWrapper/TextField.h"
#include <stdint.h>

namespace SlimProto {

class ServerPacket: public NetworkWrapper::Packet {
public:
	ServerPacket(uint16_t length, std::string operation);
	virtual ~ServerPacket();

	virtual void setLength(uint16_t);

protected:
	NetworkWrapper::NumberField myLength; //the length of the data portion of the packet - do not confuse with Packet::mySize
	NetworkWrapper::TextField myOperation;
};

}

#endif /* SERVERPACKET_H_ */
