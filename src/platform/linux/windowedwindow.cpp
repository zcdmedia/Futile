#include "windowedwindow.h"

namespace futile {

WindowedWindow::WindowedWindow(const Rectangle & bounds) : Window()
{
	this->bounds.set(bounds);
}

WindowedWindow::~WindowedWindow() { }

void WindowedWindow::move(const Rectangle & bounds)
{
	this->bounds.set(bounds);
	Window::move(this->bounds);
}

::Window WindowedWindow::create_window()
{
        assert(this->display);

        ::Window parent = RootWindow(this->display, this->vi->screen);
        ::Window window = XCreateWindow(this->display, parent,
                                        this->bounds.x, this->bounds.y,
                                        this->bounds.width, this->bounds.height,
                                        0,
                                        this->vi->depth, InputOutput,
                                        this->vi->visual, Window::VALUE_MASK,
                                        &this->attr);
        Atom wm_delete = XInternAtom(this->display, "WM_DELETE_WINDOW", True);

        const int num_protocols = 1;
        XSetWMProtocols(this->display, window, &wm_delete, num_protocols);
        XSetStandardProperties(this->display, window, "Futile", "Futile", None,
                               NULL, 0, NULL);
        XMapRaised(this->display, window);

        return window;
}

}
