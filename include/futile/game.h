/**
	@file		game.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GAME_H_
#define FUTILE_GAME_H_

#include <futile/gametime.h>
#include <futile/runnable.h>
#include <futile/graphics/graphicsdevice.h>
#include <futile/math/transform.h>
#include <futile/platform/windowable.h>
#include <futile/platform/windowfactory.h>

namespace futile {

/**
	abstract game class, handles initialization and low-level routines
 */
class Game : public Runnable {
public:
	Game();
	~Game();

	/* methods */
	void exit();
	void reset_elapsed_time();
	void tick();

	/* interfaces */
	virtual void run();

protected:
	/* primary game interface */
	virtual void draw(const GameTime & gt);
	virtual void init();
	virtual void load() = 0;
	virtual void unload() = 0;
	virtual void update(const GameTime & gt);

	GraphicsDevice graphics_device;

private:
	void game_loop();

	bool running;

	GameTime game_time;
	Windowable * window;
};

}

#endif
