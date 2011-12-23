/**
	@file		openglgraphicsenvironment.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_OPENGLGRAPHICSENVIRONMENT_H_
#define FUTILE_GRAPHICS_OPENGLGRAPHICSENVIRONMENT_H_

#include <futile/graphics/graphicsenvironment.h>

namespace futile {

class OpenGLGraphicsEnvironment : public GraphicsEnvironment {
public:
	OpenGLGraphicsEnvironment(const Vector2 & dim);
	virtual ~OpenGLGraphicsEnvironment();

	/* methods */
	virtual void init();
	virtual void resize(const Vector2 & dim);
	virtual void refresh();
};

}

#endif
