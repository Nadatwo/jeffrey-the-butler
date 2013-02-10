# Complier
CC=g++

# Library compiler

# Compiler flags
CFLAGS=-c -Wall -O0
CLIBFLAGS=-fPIC

#Linker flags
LDFLAGS=-L./lib
LIBRARIES=-lSlimProto -lNetworkWrapper -lboost_system -lpthread
LIBFLAGS=-fPIC -Wl,-G -shared

all: lib bin

bin: bin/squeeze++

lib: lib/libNetworkWrapper.so lib/libSlimProto.so

bin/squeeze++: lib/libNetworkWrapper.so lib/libSlimProto.so Squeeze++.o
	$(CC) -Wall -o bin/squeeze++ Squeeze++.o ${LDFLAGS} ${LIBRARIES}

Squeeze++.o: src/Squeeze++.cpp
	$(CC) $(CFLAGS) src/Squeeze++.cpp

# NetworkWrapper

lib/libNetworkWrapper.so: Field.o NumberField.o TextField.o Packet.o SyncServer.o
	$(CC) $(LIBFLAGS) -WL,-soname,libNetworkWrapper.so Field.o NumberField.o TextField.o Packet.o SyncServer.o -o lib/libNetworkWrapper.so

Field.o: src/NetworkWrapper/Field.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/NetworkWrapper/Field.cpp

NumberField.o: src/NetworkWrapper/Field.cpp src/NetworkWrapper/NumberField.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/NetworkWrapper/NumberField.cpp

TextField.o: src/NetworkWrapper/Field.cpp src/NetworkWrapper/TextField.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/NetworkWrapper/TextField.cpp

Packet.o: src/NetworkWrapper/Packet.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/NetworkWrapper/Packet.cpp

SyncServer.o: src/NetworkWrapper/SyncServer.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/NetworkWrapper/SyncServer.cpp

# SlimProto

lib/libSlimProto.so: lib/libNetworkWrapper.so ClientPacket.o HELOPacket.o ServerPacket.o grfbPacket.o strmPacket.o versPacket.o
	$(CC) $(LIBFLAGS) -WL,-soname,libSlimProto.so ClientPacket.o HELOPacket.o ServerPacket.o grfbPacket.o strmPacket.o versPacket.o -o lib/libSlimProto.so

ClientPacket.o: src/SlimProto/ClientPacket.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/SlimProto/ClientPacket.cpp

HELOPacket.o: src/SlimProto/HELOPacket.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/SlimProto/HELOPacket.cpp

ServerPacket.o: src/SlimProto/ServerPacket.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/SlimProto/ServerPacket.cpp

grfbPacket.o: src/SlimProto/grfbPacket.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/SlimProto/grfbPacket.cpp

strmPacket.o: src/SlimProto/strmPacket.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/SlimProto/strmPacket.cpp

versPacket.o: src/SlimProto/versPacket.cpp
	$(CC) $(CFLAGS) $(CLIBFLAGS) src/SlimProto/versPacket.cpp

# clean

clean: clean-intermediate

clean-all: clean-bin clean-lib clean-intermediate

clean-bin:
	rm -f bin/*

clean-lib:
	rm -f lib/*.so

clean-intermediate:
	rm -f *.o

.PHONY: clean clean-all clean-bin clean-lib clean-intermediate