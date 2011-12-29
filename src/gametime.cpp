#include <futile/gametime.h>

namespace futile {

GameTime::GameTime() : elapsed(0), total(0) { }

GameTime::GameTime(const TimeSpan & total, const TimeSpan & elapsed)
{
	this->total.set(total);
	this->elapsed.set(elapsed);
}

GameTime::~GameTime() { }

/* interfaces */
GameTime * GameTime::clone() const
{
	return new GameTime(this->total, this->elapsed);
}

bool GameTime::equals(const GameTime & gt) const
{
	return this->total.equals(gt.total) && this->elapsed.equals(gt.elapsed);
}

void GameTime::set(const GameTime & gt)
{
	this->total.set(gt.total);
	this->elapsed.set(gt.elapsed);
}

}
