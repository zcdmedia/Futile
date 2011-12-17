#include "xwindow.h"

/* constants */
static const unsigned long int EVENT_MASK = ExposureMask | KeyPressMask
                                            | ButtonPressMask
                                            | StructureNotifyMask;
static const unsigned long int VALUE_MASK = CWBorderPixel | CWColormap
                                            | CWEventMask | CWOverrideRedirect;

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
static inline XF86VidModeModeInfo get_mode(const futile::Dimension2D &,
                                           Display *, int);
static inline XF86VidModeModeInfo get_default_mode(Display *, int);
static inline XVisualInfo * get_visual_info(Display *, int, bool *);
static inline void set_fullscreen(Display *, int, XF86VidModeModeInfo *);
static inline ::Window create_fullscreen_window(Display *, ::Window,
                                                const XF86VidModeModeInfo *,
                                                XVisualInfo *,
                                                XSetWindowAttributes *);
static inline ::Window create_windowed_window(Display *, ::Window parent,
                                              const futile::Dimension2D &,
                                              XVisualInfo *,
                                              XSetWindowAttributes *);
static inline void opengl_init(const futile::Dimension2D &);
static inline void opengl_resize(const futile::Dimension2D &);

namespace futile {

XWindow::XWindow() : futile::Window() { }

XWindow::XWindow(const Dimension2D & dim) : futile::Window(dim, false) { }

XWindow::XWindow(const Dimension2D & dim, bool fullscreen)
	: futile::Window(dim, fullscreen) { }

XWindow::~XWindow()
{
	this->destroy();
}

void XWindow::init()
{
	this->display = XOpenDisplay(0);
	this->screen = DefaultScreen(this->display);
	this->mode = get_mode(this->dim, this->display, this->screen);

	XVisualInfo * vi = get_visual_info(this->display, this->screen,
					   &this->double_buffered);
	assert(vi);

	this->context = glXCreateContext(this->display, vi, NULL, GL_TRUE);

	::Window root = RootWindow(this->display, vi->screen);
	Colormap cmap = XCreateColormap(this->display, root, vi->visual,
					AllocNone);
	this->attr.colormap = cmap;
	this->attr.border_pixel = 0;
	this->attr.event_mask = EVENT_MASK;

	if(this->fullscreen) {
		set_fullscreen(this->display, this->screen, &this->mode);
		this->attr.override_redirect = True;
		this->window = create_fullscreen_window(this->display, root,
                                                        &this->mode, vi,
                                                        &this->attr);
	} else {
		this->window = create_windowed_window(this->display, root,
                                                      this->dim, vi,
                                                      &this->attr);
	}

	glXMakeCurrent(this->display, this->window, this->context);
	opengl_init(this->dim);
}

void XWindow::destroy()
{
	if(this->context) {
		glXDestroyContext(this->display, this->context);
		this->context = NULL;
	}

	if(this->fullscreen) {
		XF86VidModeModeInfo mode = get_default_mode(this->display,
                                                            this->screen);
		XF86VidModeSwitchToMode(this->display, this->screen, &mode);
		XF86VidModeSetViewPort(this->display, this->screen, 0, 0);
	}

	XCloseDisplay(this->display);
}

void XWindow::resize(const Dimension2D & dim)
{
	this->dim = dim;
	opengl_resize(this->dim); 
}

void XWindow::refresh() const
{
	if(this->double_buffered) {
		glXSwapBuffers(this->display, this->window);
	}
}

}

/* internal */
static inline XF86VidModeModeInfo get_mode(const futile::Dimension2D & dim,
                                           Display * display, int screen)
{
	int num_modes = 0;
	XF86VidModeModeInfo ** modes = NULL;
	XF86VidModeGetAllModeLines(display, screen, &num_modes, &modes);

	const int width = dim.get_width();
	const int height = dim.get_height();

	XF86VidModeModeInfo optimal = get_default_mode(display, screen);
	for(int i = 0; i < num_modes; i++) {
		XF86VidModeModeInfo * mode = modes[i];
		if(mode->hdisplay == width && mode->vdisplay == height) {
			optimal = *mode;
			break;
		}
	}

	XFree(modes);

	return optimal;
}

static inline XF86VidModeModeInfo get_default_mode(Display * display,
                                                   int screen)
{
	int num_modes = 0;
	XF86VidModeModeInfo ** modes = NULL;
	XF86VidModeGetAllModeLines(display, screen, &num_modes, &modes);

	XF86VidModeModeInfo mode = *modes[0];
	XFree(modes);

	return mode;
}

static inline XVisualInfo * get_visual_info(Display * display, int screen,
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

static inline void set_fullscreen(Display * display, int screen,
                                  XF86VidModeModeInfo * mode)
{
	XF86VidModeSwitchToMode(display, screen, mode);
	XF86VidModeSetViewPort(display, screen, 0, 0);
}

static inline ::Window create_fullscreen_window(Display * display,
                                                ::Window parent,
                                                const XF86VidModeModeInfo *
                                                mode,
                                                XVisualInfo * vi,
                                                XSetWindowAttributes * attr)
{
	assert(mode);
	const int width = mode->hdisplay;
	const int height = mode->vdisplay;
	::Window window = XCreateWindow(display, parent, 0, 0, width, height, 0,
                                        vi->depth, InputOutput, vi->visual,
                                        VALUE_MASK, attr);
	XWarpPointer(display, None, window, 0, 0, 0, 0, 0, 0);
	XMapRaised(display, window);
	XGrabKeyboard(display, window, True, GrabModeAsync, GrabModeAsync,
                      CurrentTime);
	XGrabPointer(display, window, True, ButtonPressMask, GrabModeAsync,
                     GrabModeAsync, window, None, CurrentTime);

	return window;
}

static inline ::Window create_windowed_window(Display * display,
                                              ::Window parent,
                                              const futile::Dimension2D & dim,
                                              XVisualInfo * vi,
                                              XSetWindowAttributes * attr)
{
	const int width = dim.get_width();
	const int height = dim.get_height();
	::Window window = XCreateWindow(display, parent, 0, 0, width, height, 0,
                                        vi->depth, InputOutput, vi->visual,
                                        VALUE_MASK, attr);
	Atom wm_delete = XInternAtom(display, "WM_DELETE_WINDOW", True);
	const int num_protocols = 1;
	XSetWMProtocols(display, window, &wm_delete, num_protocols);
	XSetStandardProperties(display, window, "Futile", "Futile", None, NULL,
                               0, NULL);
	XMapRaised(display, window);

	return window;
}

static inline void opengl_init(const futile::Dimension2D & dim)
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	opengl_resize(dim);
	glFlush();
}

static inline void opengl_resize(const futile::Dimension2D & dim)
{
	int width = dim.get_width();
	int height = dim.get_height();
	if(height <= 0) {
		height = 1;
	}

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	const GLfloat y_field_of_view = 45.0f;
	const GLfloat aspect = static_cast<GLfloat>(width)
                               / static_cast<GLfloat>(height);
	const GLfloat z_near = 0.1f;
	const GLfloat z_far = 100.0f;
	gluPerspective(y_field_of_view, aspect, z_near, z_far);
	glMatrixMode(GL_MODELVIEW);
}
