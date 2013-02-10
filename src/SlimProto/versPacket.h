/*
 * versPacket.h
 *
 *  Created on: 17 Aug 2012
 *      Author: toby
 */

#ifndef VERSPACKET_H_
#define VERSPACKET_H_

#include "ServerPacket.h"

namespace SlimProto {

class versPacket: public SlimProto::ServerPacket {
public:
	versPacket();
	virtual ~versPacket();

	virtual void updateBuffer();

	virtual void readBufferToFields();

	void setFields(std::string serverVersion);

protected:
	NetworkWrapper::TextField myServerVersion;
};

} /* namespace SlimProto */
#endif /* VERSPACKET_H_ */
