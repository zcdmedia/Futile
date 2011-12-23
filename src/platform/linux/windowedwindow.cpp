#include "windowedwindow.h"

namespace futile {

WindowedWindow::WindowedWindow(GraphicsEnvironment * gfxenv)
	: Window(gfxenv) { }

WindowedWindow::WindowedWindow(GraphicsEnvironment * gfxenv,
                               const Vector2 & pos)
	: Window(gfxenv)
{
	this->pos.set(&pos);
}

::Window WindowedWindow::create_window()
{
        assert(this->display);
	const int x = static_cast<int>(this->pos.x);
	const int y = static_cast<int>(this->pos.y);

	const Vector2 & dim = this->get_dim();
	const int width = static_cast<int>(dim.x);
	const int height = static_cast<int>(dim.y);

        ::Window parent = RootWindow(this->display, this->vi->screen);
        ::Window window = XCreateWindow(this->display, parent,
                                        x, y, width, height, 0,
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
