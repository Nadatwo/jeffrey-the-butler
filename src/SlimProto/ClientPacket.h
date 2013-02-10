/*
 * SlimProtoClientPacket.h
 *
 *  Created on: 6 Aug 2012
 *      Author: toby
 */

#ifndef CLIENTPACKET_H_
#define CLIENTPACKET_H_

#include "../NetworkWrapper/Packet.h"
#include "../NetworkWrapper/NumberField.h"
#include "../NetworkWrapper/TextField.h"
#include <stdint.h>
#include <exception>

namespace SlimProto {

class ClientPacket: public NetworkWrapper::Packet {
public:

	ClientPacket(std::string operation, uint32_t length);
	virtual ~ClientPacket();

	void setLength(uint32_t length);
	uint32_t getLength() {
		return myLength; //TODO throw "did you mean size"
	};

protected:
	const NetworkWrapper::TextField myOperation;
	NetworkWrapper::NumberField myLength; //the length of the data portion of the packet, as text - do not confuse with Packet::mySize
};

}

#endif /* CLIENTPACKET_H_ */
