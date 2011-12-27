#include <futile/graphics/texture.h>

namespace futile {

Texture::Texture(const std::string & name) : Asset(name), dim(0, 0) { }

Texture::~Texture() { }

}
