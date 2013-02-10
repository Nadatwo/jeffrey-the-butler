/*
 * HELOPacket.h
 *
 *  Created on: 8 Aug 2012
 *      Author: toby
 */

#ifndef HELOPACKET_H_
#define HELOPACKET_H_

#include "ClientPacket.h"
#include "../NetworkWrapper/NumberField.h"
#include "../NetworkWrapper/TextField.h"

namespace SlimProto {

class HELOPacket: public SlimProto::ClientPacket {
public:
	HELOPacket();
	virtual ~HELOPacket();

	virtual void updateBuffer();

	virtual void readBufferToFields();

	void setFields(uint8_t deviceID,
			uint8_t revision,
			std::string MAC,
			std::string UUID,
			uint16_t WLanChannelList,
			uint64_t BytesRecieved,
			std::string Language);

	uint8_t getDeviceID() {
		return (uint8_t)myDeviceID;
	}

	uint8_t getRevision() {
		return (uint8_t)myRevision;
	}

	std::string getMAC() {
		return (std::string)myMAC;
	}

	std::string getUUID() {
		return (std::string)myUUID;
	}

	uint16_t getWLanChannelList() {
		return (uint16_t)myWLanChannelList;
	}

	uint64_t getBytesRecieved() {
		return (uint64_t)myBytesRecieved;
	}

	std::string getLanguage() {
		return (std::string)myLanguage;
	}

protected:

	NetworkWrapper::NumberField myDeviceID;
	NetworkWrapper::NumberField myRevision;
	NetworkWrapper::TextField myMAC;
	NetworkWrapper::TextField myUUID;
	NetworkWrapper::NumberField myWLanChannelList;
	NetworkWrapper::NumberField myBytesRecieved;
	NetworkWrapper::TextField myLanguage;
	NetworkWrapper::Field myExtraData;

};

} /* namespace SlimProto */
#endif /* HELOPACKET_H_ */
