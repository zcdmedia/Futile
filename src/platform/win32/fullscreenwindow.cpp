#include "fullscreenwindow.h"

namespace futile {

FullScreenWindow::FullScreenWindow() : Window() { }

FullScreenWindow::~FullScreenWindow() { }

/* methods */
void FullScreenWindow::reposition(const Vector2 & pos) { }
void FullScreenWindow::resize(const Vector2 & dim) { }

void FullScreenWindow::init()
{
	this->Window::init();

	DEVMODE screen_settings;
	memset(&screen_settings, 0x0, sizeof(screen_settings));
	screen_settings.dmSize = sizeof(screen_settings);
	screen_settings.dmPelseWidth = this->dim.x;
	screen_settings.dmPelseHeight = this->dim.y;
	screen_settings.dmBitsPerPixel = 32;
	screen_settings.dmFields = DM_BITSPERPEL | DM_PERSWIDTH | DM_PELSHEIGHT;

	BOOL success = CDS_FULLSCREEN != DISP_CHANGE_SUCCESSFUL;
	ChangeDisplaySettings(&screen_settings, success);
}

DWORD FullScreenWindow::get_style() const
{
	return WS_POPUP;
}

DWORD FullScreenWindow::get_extended_style() const
{
	return WS_EX_APPWINDOW;
}

}
