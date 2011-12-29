#include "futile.h"

int main()
{
	futile::Game * futile = new futile::Futile();

	futile->run();

	delete futile;

	return 0;
}
