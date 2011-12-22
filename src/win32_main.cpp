#include <futile/config.h>
#include <futile/platform/windowable.h>
#include <fuitle/platform/windowfactory.h>

/* global */
futile::Windowable * window = NULL;

/* internal prototypes */
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE inst, HINSTANCE pre, LPSTR cmd, int n)
{
	const Vector2 dim(512, 512);
	//window = WindowFactory::create_window();
}

LRESULT CALLBACK WndProc(HWND inst, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch(msg) {
	default:
		return DefWindowProc(inst, msg, wparam, lparam);
	}

	return 0;
}
