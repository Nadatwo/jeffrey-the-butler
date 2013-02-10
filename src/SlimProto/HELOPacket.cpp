/*
 * HELOPacket.cpp
 *
 *  Created on: 8 Aug 2012
 *      Author: toby
 */

#include "HELOPacket.h"

namespace SlimProto {

HELOPacket::HELOPacket():
	ClientPacket("HELO", 36),
	myDeviceID("DeviceID", 1),
	myRevision("Revision", 1),
	myMAC("MAC", 6),
	myUUID("UUID", 16),
	myWLanChannelList("WLanChannelList", 2),
	myBytesRecieved("BytesRecieved", 8),
	myLanguage("Language", 2),
	myExtraData("ExtraData", 0) {
}

HELOPacket::~HELOPacket() {

}

void HELOPacket::updateBuffer() {
	uint8_t* workingBuffer = myBuffer;

	workingBuffer = updateBufferHelper(workingBuffer, myOperation);
	workingBuffer = updateBufferHelper(workingBuffer, myLength);
	workingBuffer = updateBufferHelper(workingBuffer, myDeviceID);
	workingBuffer = updateBufferHelper(workingBuffer, myRevision);
	workingBuffer = updateBufferHelper(workingBuffer, myMAC);
	workingBuffer = updateBufferHelper(workingBuffer, myUUID);
	workingBuffer = updateBufferHelper(workingBuffer, myWLanChannelList);
	workingBuffer = updateBufferHelper(workingBuffer, myBytesRecieved);
	workingBuffer = updateBufferHelper(workingBuffer, myLanguage);
	workingBuffer = updateBufferHelper(workingBuffer, myExtraData);
}

void HELOPacket::readBufferToFields() {
	uint8_t* workingBuffer = myBuffer;

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myOperation);

	if (myOperation != "HELO") {
		throw(PacketOperationMismatch());
	}

	workingBuffer = readBufferToFieldsHelper(workingBuffer, myLength);

	if (myLength == 10) { //probably softsqueeze

		workingBuffer = readBufferToFieldsHelper(workingBuffer, myDeviceID);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myRevision);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myMAC);

		myUUID.setValue("", true);
		myUUID.setActive(false);

		workingBuffer = readBufferToFieldsHelper(workingBuffer, myWLanChannelList);

		myBytesRecieved.setValue(0);
		myBytesRecieved.setActive(false);

		myLanguage.setValue("", true);
		myLanguage.setActive(false);

	} else if (myLength == 20) { //older firmware, with no UUID

		workingBuffer = readBufferToFieldsHelper(workingBuffer, myDeviceID);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myRevision);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myMAC);

		myUUID.setValue("", true);
		myUUID.setActive(false);


		workingBuffer = readBufferToFieldsHelper(workingBuffer, myWLanChannelList);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myBytesRecieved);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myLanguage);

	} else if (myLength == 36) {

		workingBuffer = readBufferToFieldsHelper(workingBuffer, myDeviceID);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myRevision);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myMAC);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myUUID);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myWLanChannelList);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myBytesRecieved);
		workingBuffer = readBufferToFieldsHelper(workingBuffer, myLanguage);

	} else	{

		// TODO handle extra data
		// TODO throw malformed packet

	}
}

void HELOPacket::setFields(uint8_t deviceID,
		uint8_t revision,
		std::string MAC,
		std::string UUID,
		uint16_t WLanChannelList,
		uint64_t bytesRecieved,
		std::string language) {
	myDeviceID.setValue(deviceID);
	myRevision.setValue(revision);
	myMAC.setValue(MAC);
	myUUID.setValue(UUID);
	myWLanChannelList.setValue(WLanChannelList);
	myBytesRecieved.setValue(bytesRecieved);
	myLanguage.setValue(language);

	updateBuffer();
}

} /* namespace SlimProto */
