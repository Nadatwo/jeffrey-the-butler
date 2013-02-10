/*
 * SlimProtoField.cpp
 *
 *  Created on: 6 Aug 2012
 *      Author: toby
 */

#include "Field.h"

namespace NetworkWrapper {

Field::Field(std::string name, unsigned short length):
	myLength(length),
	myValue(0),
	myActive(false) {
	initValue();
}

Field::Field(std::string name, unsigned short length, uint8_t* value):
	myLength(length),
	myValue(0),
	myActive(false) {
	initValue();
	setValue(value);
}

Field::~Field() {
	delete myValue;
}

void Field::setValue(uint8_t* value) {
	for (unsigned short i = 0; i < getLength(); i++) {
		myValue[i] = value[i];
	}

	setActive(true);

}

uint8_t* Field::getValue() const{
	if (!myActive) {
		throw(FieldInactiveNoValue());
	}
	return myValue;
}

void Field::initValue() {
	if (myValue == 0) {
		myValue = new uint8_t[myLength];
	} else {
		throw(FieldAlreadyInitialised());
	}
}

}
