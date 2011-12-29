#include <futile/system/timespan.h>

namespace futile {

TimeSpan::TimeSpan()
{
	this->epoch = clock();
}

TimeSpan::TimeSpan(clock_t epoch)
{
	this->epoch = epoch;
}

TimeSpan::~TimeSpan() { }

/* methods */
int TimeSpan::get_days() const
{
	return static_cast<int>(this->get_total_days());
}

int TimeSpan::get_hours() const
{
	return static_cast<int>(this->get_total_hours())
               % TimeSpan::HOURS_PER_DAY;
}

int TimeSpan::get_milliseconds() const
{
	return static_cast<int>(this->get_total_milliseconds())
               % TimeSpan::MILLISECONDS_PER_SECOND;
}

int TimeSpan::get_minutes() const
{
	return static_cast<int>(this->get_total_minutes())
               % TimeSpan::MINUTES_PER_HOUR;
}

int TimeSpan::get_seconds() const
{
	return static_cast<int>(this->get_total_seconds())
               % TimeSpan::SECONDS_PER_MINUTE;
}

clock_t TimeSpan::get_ticks() const
{
	return clock() - this->epoch;
}

double TimeSpan::get_total_days() const
{
	return this->get_total_seconds() / TimeSpan::SECONDS_PER_DAY;
}

double TimeSpan::get_total_hours() const
{
	return this->get_total_seconds() / TimeSpan::SECONDS_PER_HOUR;
}

double TimeSpan::get_total_milliseconds() const
{
	return this->get_total_seconds() * TimeSpan::MILLISECONDS_PER_SECOND;
}

double TimeSpan::get_total_minutes() const
{
	return this->get_total_seconds() / TimeSpan::SECONDS_PER_MINUTE;
}

double TimeSpan::get_total_seconds() const
{
	return this->get_ticks() / static_cast<double>(CLOCKS_PER_SEC);
}

/* interfaces */
TimeSpan * TimeSpan::clone() const
{
	return new TimeSpan(this->epoch);
}

bool TimeSpan::equals(const TimeSpan & t) const
{
	return this->epoch == t.epoch;
}

void TimeSpan::set(const TimeSpan & t)
{
	this->epoch = t.epoch;
}

}
