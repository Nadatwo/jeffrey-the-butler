/*
 * Squeeze++.cpp
 *
 *  Created on: 17 Aug 2012
 *      Author: toby
 */
#include <stdlib.h>
#include <iostream>
#include <exception>
#include "NetworkWrapper/SyncServer.h"
#include "SlimProto/strmPacket.h"
#include "SlimProto/HELOPacket.h"
#include "SlimProto/versPacket.h"
#include "SlimProto/grfbPacket.h"


int main() {
	try{
		SlimProto::strmPacket myStrm;

		myStrm.setFields("t",
				1,
				"o",
				1,
				3,
				2,
				0,
				2,
				0,
				2,
				1,
				0x80,
				2,
				0,
				9000,
				0,
				"GET /stream.mp3 HTTP/1.0\r\n\r\n");

		SlimProto::strmPacket myStrm2;

		myStrm2.setFields("t",
				1,
				"o",
				1,
				3,
				2,
				0,
				2,
				0,
				2,
				1,
				0x80,
				2,
				0,
				9000,
				0,
				"GET www.planetrock.com/planetrock.m3u HTTP/1.0\r\n\r\n");

		SlimProto::HELOPacket myHELO;

		SlimProto::versPacket myVers;
		myVers.setFields("vers6.5.4");

		SlimProto::grfbPacket myGrfb;
		myGrfb.setFields(2);

		NetworkWrapper::SyncServer myServer(3483);

		std::cout << "Listening..." << std::endl;

		myServer.listen();

		std::cout << "Receiving HELO" << std::endl;

		myServer.blindReceive(myHELO);

		myHELO.readBufferToFields();

		myServer.send(myVers);

		std::cout << "Sent Version" << std::endl;

		myServer.send(myStrm2);

		std::cout << "Sent STRM" << std::endl;

//		std::cout << "Sending 2^16 brightness commands" << std::endl;
//
//		for (uint16_t i=1; i != 0; i++) {
//			std::cout << "Sent Brightness #" << i << ": " << i%6 << std::endl;
//
//			myGrfb.setFields(i%6);
//			myServer.send(myGrfb);
//		}
//
//		std::cout << "Sent Brightnesses" << std::endl;

		myServer.close();

		std::cout << "Connection received: exiting" << std::endl;

	} catch (std::exception& e) {

		std::cout << "Exception caught at top level: " << e.what();

	} catch (...) {

		std::cout << "Unknown exception caught at top level";

	}

	//return EXIT_SUCCESS;
}

