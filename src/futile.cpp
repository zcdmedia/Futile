#include "futile.h"

#include <pngio.h>

namespace futile {

Futile::Futile() : camera(&this->graphics_device) { }

Futile::~Futile() { }

void Futile::init()
{
	Game::init();
}

void Futile::load()
{
	struct pngio_t p;
	pngio_init(&p);
	pngio_read(&p, "omg.png");

	char * data = NULL;
	pngio_image_data(&p, (png_byte **) &data);

	int size = pngio_size(&p);

	std::stringstream ss(std::ios_base::binary | std::ios_base::in | std::ios_base::out);
	ss.write(data, size);

	this->texture.image_data.read(ss);
	this->texture.dim.x = p.width;
	this->texture.dim.y = p.height;

	this->texture.init();

	pngio_destroy(&p);
}

void Futile::unload()
{
}

void Futile::update(const GameTime & gt)
{
	static int i = 0;
	i++;

	if(i > 100) this->exit();

	this->camera.update(gt);
}

void Futile::draw(const GameTime & gt)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	const Matrix4 & xform = this->camera.get_transform();

	this->sb.begin(xform);
	this->sb.draw(this->texture, Vector2(0.0f, 0.0f));
	this->sb.end();

	Game::draw(gt);
}

}
