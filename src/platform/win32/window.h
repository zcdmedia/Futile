/**
	@file		window.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_WIN32_WINDOW_H_
#define FUTILE_PLATFORM_WIN32_WINDOW_H_

#include <cassert>

#include <windows.h>

#include <futile/math/vector2.h>
#include <futile/platform/windowable.h>

namespace futile {

/**
	win32 Window abstract class
 */
class Window : public Windowable {
public:
	Window();
	virtual ~Window();

	/* accessors */
	virtual const Vector2 & get_dim() const;
	virtual const Vector2 & get_pos() const;

	/* methods */
	virtual void init();
	virtual void destroy();
	virtual void reposition(const Vector2 & pos);
	virtual void resize(const Vector2 & dim);
	virtual void refresh();

protected:
	virtual DWORD get_style() const = 0;
	virtual DWORD get_extended_style() const = 0;

	Vector2 dim;
	Vector2 pos;

private:
	HINSTANCE inst;
	mutable HWND handle;
	HGLRC context;

	Window(const Window &);
	Window & operator=(const Window &);
};

}

#endif
