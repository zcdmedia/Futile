/**
	@file		settable.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_SETTABLE_H_
#define FUTILE_SETTABLE_H_

namespace futile {

/**
	interfaces for classes providing an explicit copy method.  unlike
	a copy constructor, the set method must be called explicitly
 */
template<typename T> class Settable {
public:
	virtual void set(T t) = 0;
};

}

#endif
