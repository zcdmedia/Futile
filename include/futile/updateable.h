/**
	@file		updateable.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_UPDATEABLE_H_
#define FUTILE_UPDATEABLE_H_

#include <futile/gametime.h>

namespace futile {

/**
	interface for any component that needs to be updated
 */
class Updateable {
public:
	virtual void update(const GameTime & gt) = 0;
};

}

#endif
