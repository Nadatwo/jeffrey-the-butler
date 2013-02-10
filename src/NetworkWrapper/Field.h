/*
 * SlimProtoField.h
 *
 *  Created on: 6 Aug 2012
 *      Author: toby
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <exception>

namespace NetworkWrapper {

class Field {
public:
	Field(std::string name, unsigned short length);
	Field(std::string name, unsigned short length, uint8_t* value);
	virtual ~Field();

	static class FieldTooSmall: public std::exception {
		virtual const char* what() const throw() {
		    return "Field is too small to hold value";
		  }
	} exFieldTooSmall;

	static class FieldTooBig: public std::exception {
		virtual const char* what() const throw() {
		    return "Field is too big to hold value";
		  }
	} exFieldTooBig;

	static class FieldAlreadyInitialised: public std::exception {
		virtual const char* what() const throw() {
		    return "Field is already initialised";
		  }
	} exFieldAlreadyInitialised;

	static class FieldActiveSizeChange: public std::exception {
		virtual const char* what() const throw() {
		    return "Attempt to change size of active field";
		  }
	} exFieldActiveSizeChange;

	static class FieldInactiveNoValue: public std::exception {
		virtual const char* what() const throw() {
		    return "Attempt to get value of inactive field";
		  }
	} exFieldInactiveNoValue;

	virtual bool operator==(const uint8_t*& rValue) const {
		if (myValue == rValue) {
			return true;
		} else {
			return false;
		}
	}

	virtual bool operator!=(const uint8_t*& rValue) const {
		return !(*this == rValue);
	}

	virtual void setValue(uint8_t* value);

	std::string getName() const {
		return myName;
	}

	void setName(std::string name) {
		myName = name;
	}

	uint8_t* getValue() const;

	unsigned short getLength() const {
		return myLength;
	}

	void setLength(short length) {
		if (myActive) {
			throw(FieldActiveSizeChange());
		}
		myLength = length;
	}

	void setActive(bool active) {
		myActive = active;
	}

	bool getActive() const {
		return myActive;
	}

protected:
	void initValue();
	std::string myName;
	unsigned short myLength;
	uint8_t* myValue;
	bool myActive;
};

}


#endif /* FIELD_H_ */
