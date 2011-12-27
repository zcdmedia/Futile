/**
	@file		serializable.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_SERIALIZABLE_H_
#define FUTILE_SERIALIZABLE_H_

#include <futile/rawbuffer.h>

namespace futile {

/**
	interface for classes that need to be written to media
 */
template<typename T> class Serializable {
public:
	virtual RawBuffer * serialize() const = 0;
	virtual T deserialize(const RawBuffer & data) = 0;
};

}

#endif
