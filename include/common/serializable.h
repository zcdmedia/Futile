/**
	@file		serializable.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_SERIALIZABLE_H_
#define FUTILE_SERIALIZABLE_H_

namespace futile {

/**
	interface for classes that need to provide
	serialization/deserialization functionality
 */
class Serializable {
public:
	virtual void serialize() const = 0;
	virtual void deserialize() = 0;
};

}

#endif
