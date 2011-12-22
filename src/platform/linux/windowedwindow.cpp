#include "windowedwindow.h"

namespace futile {

WindowedWindow::WindowedWindow() : Window() { }

WindowedWindow::WindowedWindow(const Vector2 & dim) : Window()
{
	this->dim.set(&dim);
}

WindowedWindow::WindowedWindow(const Vector2 & dim, const Vector2 & pos)
	: Window()
{
	this->dim.set(&dim);
	this->pos.set(&pos);
}

::Window WindowedWindow::create_window()
{
        assert(this->display);
        ::Window parent = RootWindow(this->display, this->vi->screen);
        ::Window window = XCreateWindow(this->display, parent,
                                        this->pos.x, this->pos.y,
                                        this->dim.x, this->dim.y, 0,
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
