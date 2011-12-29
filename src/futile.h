/**
	@file		futile.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_FUTILE_H_
#define FUTILE_FUTILE_H_

#include <sstream>

#include <futile/game.h>
#include <futile/graphics/spritebatch.h>
#include <futile/graphics/texture2d.h>
#include <futile/math/matrix4.h>

namespace futile {

/**
	test game class for development
 */
class Futile : public Game {
public:
	Futile();
	~Futile();

protected:
	virtual void init();
	virtual void load();
	virtual void unload();
	virtual void update(const GameTime & gt);
	virtual void draw(const GameTime & gt);

private:
	SpriteBatch sb;
	Texture2D texture;
};

}

#endif
