/*
 * grfbPacket.h
 *
 *  Created on: 06 Jan 2013
 *      Author: toby
 */

#ifndef GRFBPACKET_H_
#define GRFBPACKET_H_

#include "ServerPacket.h"

namespace SlimProto {

class grfbPacket: public SlimProto::ServerPacket {
public:
	grfbPacket();
	virtual ~grfbPacket();

	virtual void updateBuffer();

	virtual void readBufferToFields();

	void setFields(uint16_t brightness);

protected:
	NetworkWrapper::NumberField myBrightness;
};

} /* namespace SlimProto */
#endif /* GRFBPACKET_H_ */
