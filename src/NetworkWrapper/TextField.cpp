/*
 * TextField.cpp
 *
 *  Created on: 17 Aug 2012
 *      Author: toby
 */

#include "TextField.h"
#include <stdexcept>

namespace NetworkWrapper {

TextField::TextField(std::string name, unsigned short length):
	Field(name, length) {

}

TextField::TextField(std::string name, unsigned short length, std::string value):
	Field(name, length) {

	setValue(value);

}

TextField::~TextField() {
	// TODO Auto-generated destructor stub
}

bool TextField::operator==(const std::string& rValue) const {
	for (unsigned short i = 0; i < myLength; i++) {
		try {
			if (myValue[i] != rValue.at(i)) {
				return false;
			}
		} catch (std::out_of_range& e) {
			return false;
		}
	}
	return true;
}

TextField::operator std::string() {
	std::string rValue = "";

	for (unsigned short i = 0; i < myLength; i++) {
		rValue.push_back(myValue[i]);
	}

	return rValue;
}

void TextField::setValue(std::string value, bool padSpaces) {
	if (value.length() != myLength) {
		if (value.length() > myLength) {
			throw(FieldTooSmall());
			return;
		} else if (value.length() < myLength && !padSpaces) {
			throw(FieldTooBig());
			return;
		}
	}
	for (unsigned short i = 0; i < value.length(); i++) {
		myValue[i] = value[i];
	}
	for (short i = value.length(); i < myLength && padSpaces; i++) {
		myValue[i] = ' ';
	}

	setActive(true);

}

} /* namespace SlimProto */
