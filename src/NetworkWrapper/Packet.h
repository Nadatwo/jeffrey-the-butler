/*
 * SlimProtoPacket.h
 *
 *  Created on: 6 Aug 2012
 *      Author: toby
 */

#ifndef PACKET_H_
#define PACKET_H_

#include <stdint.h>
#include <string>
#include "Field.h"

namespace NetworkWrapper {

class Packet {
public:
	Packet(short size);
	Packet(short size, uint8_t* buffer);
	virtual ~Packet();

	static class PacketOperationMismatch: public std::exception {
		virtual const char* what() const throw() {
		    return "The type of Packet and Operation value do not match";
		  }
	} exPacketOperationMismatch;

	short getSize() const{
		return mySize;
	}

	void setSize(unsigned short size);

	uint8_t* getBuffer() {
		return myBuffer;
	}

	virtual void updateBuffer();

	std::string toString();

protected:

	virtual void readBufferToFields();

	// put the value from "data" into memory at "buffer", returning the byte after the end of the added data
	uint8_t* updateBufferHelper(uint8_t* buffer, Field data);

	// get a value from "buffer", according to the size of "data", returning the byte after the end of the read data
	uint8_t* readBufferToFieldsHelper(uint8_t* buffer, Field data);

	unsigned short mySize; //the size of the whole packet, in bytes
	uint8_t* myBuffer;
};

}

#endif /* PACKET_H_ */
