/*
 * Server.cpp
 *
 *  Created on: 19 Aug 2012
 *      Author: toby
 */

#include "SyncServer.h"

namespace NetworkWrapper {

SyncServer::SyncServer(unsigned short port):
	myPort(port),
	myIOService(1),
	myAcceptor(myIOService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), myPort)),
	mySocket(myIOService) {

	//myIOService.run();
}

SyncServer::~SyncServer() {
	//mySocket.close();
	//myIOService.stop();
}

void SyncServer::listen() {
	myAcceptor.accept(mySocket);
}

void SyncServer::send(NetworkWrapper::Packet packet) {
	boost::asio::write(mySocket, boost::asio::buffer(packet.getBuffer(), packet.getSize()));
}

void SyncServer::blindReceive(NetworkWrapper::Packet packet) {
	boost::asio::read(mySocket, boost::asio::buffer(packet.getBuffer(), packet.getSize()));
}

void SyncServer::close() {
	mySocket.close();
}

} /* namespace NetworkWrapper */
