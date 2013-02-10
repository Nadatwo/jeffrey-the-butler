/*
 * NumberField.h
 *
 *  Created on: 17 Aug 2012
 *      Author: toby
 */

#ifndef NUMBERFIELD_H_
#define NUMBERFIELD_H_

#include "Field.h"
#include <stdint.h>

namespace NetworkWrapper {

class NumberField: public NetworkWrapper::Field {
public:
	NumberField(std::string name, unsigned short length);
	NumberField(std::string name, unsigned short length, size_t value);
	virtual ~NumberField();

	virtual bool operator==(const size_t& rValue) const;

	virtual bool operator!=(const size_t& rValue) const {
		return !(*this == rValue);
	}

	virtual operator uint8_t();
	virtual operator uint16_t();
	virtual operator uint32_t();
	virtual operator uint64_t();

	void setValue(long value);
};

} /* namespace SlimProto */
#endif /* NUMBERFIELD_H_ */
