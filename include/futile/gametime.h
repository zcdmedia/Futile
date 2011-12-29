/**
	@file		gametime.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GAMETIME_H_
#define FUTILE_GAMETIME_H_

#include <futile/cloneable.h>
#include <futile/equatable.h>
#include <futile/settable.h>
#include <futile/system/timespan.h>

namespace futile {

class GameTime : public Cloneable<GameTime *>, public Equatable<const GameTime &>, public Settable<const GameTime &> {
public:
	GameTime();
	GameTime(const TimeSpan & total, const TimeSpan & elapsed);
	~GameTime();

	/* access */
	inline const TimeSpan & get_elapsed_time() const
	{
		return this->elapsed;
	}

	inline const TimeSpan & get_total_time() const
	{
		return this->total;
	}

	/* methods */
	inline void tick() { this->elapsed.reset(); }
	inline void reset()
	{
		this->total.reset();
		this->elapsed.reset();
	}

	/* interfaces */
	virtual GameTime * clone() const;
	virtual bool equals(const GameTime & gt) const;
	virtual void set(const GameTime & gt);

private:
	TimeSpan elapsed;
	TimeSpan total;

	GameTime(const GameTime &);
	GameTime & operator=(const GameTime &);
};

}

#endif
