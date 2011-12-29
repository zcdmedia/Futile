#include "futile.h"

#include <pngio.h>

namespace futile {

Futile::Futile() { }

Futile::~Futile() { }

void Futile::init()
{
	Game::init();
}

void Futile::load()
{
	struct pngio_t p;
	pngio_init(&p);
	int i = pngio_read(&p, "omg.png");

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
}

void Futile::draw(const GameTime & gt)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Matrix4 m;
	m.identity();
	Transform::load_matrix(&m);

	Vector3 eye(0.0f, 0.0f, 10.0f);
	Vector3 center(0.0f, 0.0f, 0.0f);
	Vector3 up(0.0f, 1.0f, 0.0f);
	Transform::look_at(eye, center, up, &m);
	Transform::load_matrix(&m);

	this->sb.begin();
	this->sb.draw(this->texture, Rectangle());
	this->sb.end();

	Game::draw(gt);
}

}
