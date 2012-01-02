#include "window.h"

/* static */
static int sgl_buf_attr[] = {
	GLX_RGBA,
	GLX_RED_SIZE, 4,
	GLX_GREEN_SIZE, 4,
	GLX_BLUE_SIZE, 4,
	GLX_DEPTH_SIZE, 16,
	None
};

static int dbl_buf_attr[] = {
	GLX_RGBA, GLX_DOUBLEBUFFER,
	GLX_RED_SIZE, 4,
	GLX_GREEN_SIZE, 4,
	GLX_BLUE_SIZE, 4,
	GLX_DEPTH_SIZE, 16,
	None
};

/* internal prototypes */
static XF86VidModeModeInfo get_mode(const futile::Rectangle &, Display *, int);
static XF86VidModeModeInfo get_default_mode(Display *, int);

static XVisualInfo * get_visual_info(Display *, int, bool *);

static inline void revert_mode(Display *, int);

namespace futile {

Window::Window()
{
	this->double_buffered = false;

	this->context = NULL;
	this->display = NULL;
	this->vi = NULL;
}

Window::~Window()
{
	this->destroy();
}

void Window::init()
{
	this->display = XOpenDisplay(NULL);
	this->screen = DefaultScreen(this->display);
	this->mode = get_default_mode(this->display, this->screen);
	this->vi = get_visual_info(this->display, this->screen,
                                   &this->double_buffered);
	assert(this->vi);

	this->context = glXCreateContext(this->display, this->vi, NULL,
                                         GL_TRUE);

	::Window root = RootWindow(this->display, this->vi->screen);
	Colormap cmap = XCreateColormap(this->display, root, this->vi->visual,
					AllocNone);
	this->attr.colormap = cmap;
	this->attr.border_pixel = 0;
	this->attr.event_mask = EVENT_MASK;
	this->window = this->create_window();

	bool set = glXMakeCurrent(this->display, this->window, this->context);
	assert(set);
}

void Window::destroy()
{
	if(!(this->display)) return;

	if(this->context) {
		glXDestroyContext(this->display, this->context);
		this->context = NULL;
	}

	if(this->vi) {
		XFree(this->vi);
		this->vi = NULL;
	}

	revert_mode(this->display, this->screen);

	XCloseDisplay(this->display);
	this->display = NULL;
}

void Window::move(const Rectangle & bounds)
{
	XMoveResizeWindow(this->display, this->window, bounds.x, bounds.y,
                          bounds.width, bounds.height);
}

void Window::refresh()
{
	assert(this->display && this->window);
	glXSwapBuffers(this->display, this->window);
}

}

/* internal */
static XF86VidModeModeInfo get_mode(const futile::Rectangle & bounds,
                                    Display * display, int screen)
{
	int num_modes = 0;
	XF86VidModeModeInfo ** modes = NULL;
	XF86VidModeGetAllModeLines(display, screen, &num_modes, &modes);

	XF86VidModeModeInfo optimal = get_default_mode(display, screen);
	for(int i = 0; i < num_modes; i++) {
		XF86VidModeModeInfo * mode = modes[i];
		if(mode->hdisplay == bounds.width && mode->vdisplay == bounds.height) {
			optimal = *mode;
			XFree(modes);
			return optimal;
		}
	}

	XFree(modes);

	return optimal;
}

static XF86VidModeModeInfo get_default_mode(Display * display, int screen)
{
	int num_modes = 0;
	XF86VidModeModeInfo ** modes = NULL;
	XF86VidModeGetAllModeLines(display, screen, &num_modes, &modes);

	XF86VidModeModeInfo mode = *modes[0];
	XFree(modes);

	return mode;
}

static XVisualInfo * get_visual_info(Display * display, int screen,
                                     bool * double_buffered)
{
	XVisualInfo * vi = glXChooseVisual(display, screen, dbl_buf_attr);
	if(!(vi)) {
		vi = glXChooseVisual(display, screen, sgl_buf_attr);
		*double_buffered = false;
	} else {
		*double_buffered = true;
	}

	return vi;
}

static inline void revert_mode(Display * display, int screen)
{
	XF86VidModeModeInfo mode = get_default_mode(display, screen);
	XF86VidModeSwitchToMode(display, screen, &mode);
	XF86VidModeSetViewPort(display, screen, 0, 0);
}
