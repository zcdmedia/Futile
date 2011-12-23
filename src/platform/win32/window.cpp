#include "window.h"

/* internal prototypes */
static inline void init_window_rect(const futile::Vector2 &,
                                    const futile::Vector2 &, RECT *);
static inline void init_extended_class(const HINSTANCE &, WNDCLASSEX *);
static inline void register_extended_class(WNDCLASSEX *);

static inline void opengl_init(HWND, HGLRC *);
static inline void opengl_resize(HWND, const futile::Vector2 &);
static inline void configure_pixel_format(HDC);

namespace futile {

Window::Window() : dim(1, 1), pos(0, 0) { }

Window::~Window()
{
	this->destroy();
}

/* methods */
void Window::init()
{
	RECT rect;
	init_window_rect(this->dim, this->pos, &rect);

	WNDCLASSEX wndcls;
	init_extended_class(this->inst, &wndcls);
	register_extended_class(&wndcls);

	const DWORD style = this->get_style();
	const DWORD estyle = this->get_extended_style();

	AdjustWindowRectEx(&this->rect, style, FALSE, estyle);
	this->handle = CreateWindowEx(
		NULL,
		"Futile",
		"Futile",
		style | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		this->pos.x, this->pos.y,
		this->dim.x, this->dim.y,
		NULL,		/* parent handle */
		NULL,		/* menu hande */
		this->inst,
		NULL		/* auxilary params */
	);

	assert(this->handle);
	ShowWindow(this->handle, SW_SHOW);
}

void Window::destroy()
{
	HDC device_context = GetDC(this->handle);
	wglMakeCurrent(device_context, NULL);
	wglDeleteContext(this->context);
	DestroyWindow(this->handle);
	ChangeDisplaySettings(NULL, 0);
	ShowCursor(TRUE);
}

void Window::reposition(const Vector2 & pos)
{
	this->pos.set(&pos);
	BOOL moved = MoveWindow(this->handle, this->pos.x, this->pos.y,
                                this->dim.x, this->dim.y, TRUE);
	assert(moved == TRUE);
}

void Window::resize(const Vector2 & dim)
{
	this->dim.set(&dim);
	Bool moved = MoveWindow(this->handle, this->pos.x, this->pos.y,
                                this->dim.x, this->dim.y, TRUE);
	assert(moved == TRUE);
}

void Window::refresh()
{
	UpdateWindow(this->handle);
}

}

/* internal */
static inline void init_window_rect(const futile::Vector2 & dim,
                                    const futile::Vector2 & pos, RECT * rect)
{
	assert(rect);
	rect->left = static_cast<long int>(pos.x);

	rect->right = rect->left + static_cast<long int>(dim.x);
	rect->top = static_cast<long int>(pos.y);

	rect->bottom = rect->top + static_cast<long int>(dim.y);
}

static inline void init_extended_class(const HINSTANCE & inst,
                                       WNDCLASSEX * wndcls)
{
	assert(wndcls);

	wndcls->cbSize = sizeof(*wndcls);
	wndcls->style = CS_HREDRAW | CS_VREDRAW;
	wndcls->lpfnWndProc = WndProc;
	wndcls->cbClsExtra = 0;
	wndcls->cbWndExtra = 0;
	wndcls->hInstance = inst;
	wndcls->hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls->hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls->hbrBackground = NULL;
	wndcls->lpszMenuName = NULL;
	wndcls->lpszClassName = "Futile";
	wndcls->hIconSm = LoadIcon(NULL, IDI_WINLOGO);
}

static inline void register_extended_class(WNDCLASSEX * wndcls)
{
	assert(RegisterClassEx(wndcls));
}

static inline void opengl_init(HWND handle, HGLRC * context)
{
	HDC device_context = GetDC(handle);
	configure_pixel_format(device_context);
	*context = wglCreateContext(device_context);
	wglMakeCurrent(device_context, glcontext);
}

static inline void opengl_resize(HWND handle, const futile::Vector2 & dim)
{
	const int width = dim.x <= 0 ? 1 : dim.x;
	const int height = dim.y <= 0 ? 1 : dim.y;

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
	glLoadIdentity();
}

static inline void configure_pixel_format(HDC device_context)
{
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(pfd),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		32,			/* 32-bit color mode */
		0, 0, 0, 0, 0, 0,	/* ignore color bits */
		0,			/* no alpha buffer */
		0,			/* ignore shift bit */
		0,			/* no accumulation buffer */
		0, 0, 0, 0,		/* ignore accumulation bits */
		16,			/* 16-bit z-buffer */
		0,			/* no stencil buffer */
		0,			/* no aux buffer */
		PFD_MAIN_PLANE,		/* main drawing plane */
		0,			/* reserved */
		0, 0, 0, 0		/* ignore layer masks */
	};

	const int pixel_format = ChoosePixelFormat(device_context, &pfd);
	SetPixelFormat(device_context, pixel_format, &pfd);
}
