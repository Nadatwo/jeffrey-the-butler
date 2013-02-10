/*
 * NumberField.cpp
 *
 *  Created on: 17 Aug 2012
 *      Author: toby
 */

#include "NumberField.h"
#include <string.h>

namespace NetworkWrapper {

NumberField::NumberField(std::string name, unsigned short length):
			Field(name, length) {

}

NumberField::NumberField(std::string name, unsigned short length, size_t value):
			Field(name, length) {

	setValue(value);

}

NumberField::~NumberField() {
	// TODO Auto-generated destructor stub
}

bool NumberField::operator==(const size_t& rValue) const {
	for (unsigned short i = 0; i < myLength; i++) {
		uint8_t partRValue = rValue >> (8 * i);
		if (myValue[i] != partRValue) {
			return false;
		}
	}
	return true;
}

void NumberField::setValue(long value) {
	//if (sizeof(value) != myLength) {
	//	if (sizeof(value) > myLength) {
	//		throw(FieldTooSmall());
	//		return;
	//	}
	//}
	// TODO see if the size can be checked
	for (short i = sizeof(value); i < myLength; i++) {
		myValue[i] = 0;
	}
	for (unsigned short i = 0; i < sizeof(value); i++) {
		myValue[i] = uint8_t(value >> (i * 8));
	}

	setActive(true);

}

NumberField::operator uint8_t() {
	uint8_t rValue = 0;
	void* valueStart = myValue + myLength - sizeof(uint8_t);
	memcpy(&rValue, valueStart, sizeof(uint8_t));
	return rValue;
}

NumberField::operator uint16_t() {
	uint16_t rValue = 0;
	void* valueStart = myValue + myLength - sizeof(uint16_t);
	memcpy(&rValue, valueStart, sizeof(uint16_t));
	return rValue;
}

NumberField::operator uint32_t() {
	uint32_t rValue = 0;
	void* valueStart = myValue + myLength - sizeof(uint32_t);
	memcpy(&rValue, valueStart, sizeof(uint32_t));
	return rValue;
}

NumberField::operator uint64_t() {
	uint64_t rValue = 0;
	void* valueStart = myValue + myLength - sizeof(uint64_t);
	memcpy(&rValue, valueStart, sizeof(uint64_t));
	return rValue;
}

} /* namespace SlimProto */
