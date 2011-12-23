/**
	@file		equatable.h
	@brief		Matthew Hinkle
 */

#ifndef FUTILE_EQUATABLE_H_
#define FUTILE_EQUATABLE_H_

namespace futile {

/**
	interface for classes providing object equality testing
 */
template<typename T> class Equatable {
public:
	virtual bool equals(T) const = 0;
};

}

#endif
