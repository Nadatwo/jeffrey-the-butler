/*
 * Server.h
 *
 *  Created on: 19 Aug 2012
 *      Author: toby
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <boost/asio.hpp>
#include "Packet.h"

namespace NetworkWrapper {

class SyncServer {
public:
	SyncServer(unsigned short port);
	virtual ~SyncServer();

	void listen();

	void send(NetworkWrapper::Packet packet);

	//receive into provided packet, leaving the packet to determine if he received packet fits
	void blindReceive(NetworkWrapper::Packet packet);

	//receive into a generic packet, and determine what kind of packet has been provided
	//TODO void blindReceive(NetworkWrapper::Packet packet);

	void close();

	void setPort(unsigned short port) {
		myPort = port;
	}

	unsigned short getPort() const {
		return myPort;
	}

protected:
	unsigned short myPort;
	boost::asio::io_service myIOService;
	boost::asio::ip::tcp::acceptor myAcceptor;
	boost::asio::ip::tcp::socket mySocket;
};

} /* namespace NetworkWrapper */
#endif /* SERVER_H_ */
