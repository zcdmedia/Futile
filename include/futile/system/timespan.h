/**
	@file		timespan.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_SYSTEM_TIMESPAN_H_
#define FUTILE_SYSTEM_TIMESPAN_H_

#include <ctime>

#include <futile/cloneable.h>
#include <futile/equatable.h>
#include <futile/settable.h>

namespace futile {

class TimeSpan : public Cloneable<TimeSpan *>, public Equatable<const TimeSpan &>, public Settable<const TimeSpan &> {
public:
	TimeSpan();
	explicit TimeSpan(clock_t epoch);
	~TimeSpan();

	/* methods */
	int get_days() const;
	int get_hours() const;
	int get_minutes() const;
	int get_milliseconds() const;
	int get_seconds() const;

	clock_t get_ticks() const;

	double get_total_days() const;
	double get_total_hours() const;
	double get_total_milliseconds() const;
	double get_total_minutes() const;
	double get_total_seconds() const;

	inline void reset() { this->epoch = 0; }

	/* interfaces */
	virtual TimeSpan * clone() const;
	virtual bool equals(const TimeSpan & t) const;
	virtual void set(const TimeSpan & t);

	static const int HOURS_PER_DAY;
	static const int MILLISECONDS_PER_SECOND;
	static const int MINUTES_PER_HOUR;
	static const int MINUTES_PER_DAY;
	static const int SECONDS_PER_MINUTE;
	static const int SECONDS_PER_HOUR;
	static const int SECONDS_PER_DAY;

private:
	clock_t epoch;

	TimeSpan(const TimeSpan &);
	TimeSpan & operator=(const TimeSpan &);
};

}

#endif
