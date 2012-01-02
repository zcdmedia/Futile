#include <futile/game.h>

#include <iostream>
using namespace std;

namespace futile {

Game::Game()
{
	this->window = NULL;
}

Game::~Game()
{
	if(this->window) {
		delete this->window;
		this->window = NULL;
	}
}

/* methods */
void Game::exit()
{
	this->running = false;
}

void Game::reset_elapsed_time()
{
	this->game_time.tick();
}

void Game::tick()
{
	this->reset_elapsed_time();
	this->update(this->game_time);
	this->draw(this->game_time);
}

/* interfaces */
void Game::run()
{
	this->init();
	this->load();
	this->game_loop();
	this->unload();

	if(this->window) {
		this->window->destroy();
	}
}

/* primary game interface */
void Game::draw(const GameTime & gt)
{
	/* base rendering logic */
	this->window->refresh();
}

void Game::init()
{
	this->window = WindowFactory::create_fullscreen_window();
	this->window->init();

	this->graphics_device.get_viewport()->set_bounds(Rectangle(0, 0, 1366, 768));
	this->game_time.reset();
	this->running = true;
}

void Game::update(const GameTime & gt)
{
	/* base game update logic */
	/* initiate input events here */
}

void Game::game_loop()
{
	while(this->running) {
		this->tick();
	}
}

}
