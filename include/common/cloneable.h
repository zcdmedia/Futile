/**
	@file		cloneable.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_CLONEABLE_H_
#define FUTILE_CLONEABLE_H_

namespace futile {

/**
	interface for classes providing object copying
 */
template<typename T> class Cloneable {
public:
	virtual T clone() const = 0;
};

}

#endif
