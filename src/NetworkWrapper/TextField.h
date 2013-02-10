/*
 * TextField.h
 *
 *  Created on: 17 Aug 2012
 *      Author: toby
 */

#ifndef TEXTFIELD_H_
#define TEXTFIELD_H_

#include "Field.h"
#include <string>

namespace NetworkWrapper {

class TextField: public NetworkWrapper::Field {
public:
	TextField(std::string name, unsigned short length);
	TextField(std::string name, unsigned short length, std::string value);
	virtual ~TextField();

	virtual bool operator==(const std::string& rValue) const;

	virtual bool operator!=(const std::string& rValue) const {
		return !(*this == rValue);
	}

	virtual operator std::string();

	void setValue(std::string value, bool padSpaces = false);
};

} /* namespace SlimProto */
#endif /* TEXTFIELD_H_ */
