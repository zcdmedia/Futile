/**
	@file		runnable.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_RUNNABLE_H_
#define FUTILE_RUNNABLE_H_

namespace futile {

/**
	classes which intend to do work in a seperate thread should implement
	Runnable
 */
class Runnable {
public:
	virtual void run() = 0;
};

}

#endif
