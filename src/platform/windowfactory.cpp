#include <futile/platform/windowfactory.h>

#if Futile_LINUX
# include "xwindow.h"
# include "xfullscreenwindow.h"
# include "xwindowedwindow.h"
#endif

namespace futile {

WindowFactory::~WindowFactory() { }

Window * WindowFactory::create_window(const Vector2 & dim)
{
#if Futile_APPLE
	/* return a cocoa window */
	return NULL;
#elif Futile_LINUX
	return new XWindowedWindow(dim);
#elif Futile_WIN32
	/* return a windows window */
	return NULL;
#else
# error build platform is not supported
	return NULL;
#endif
}

Window * WindowFactory::create_fullscreen_window()
{
#if Futile_APPLE
	/* return a cocoa window */
	return NULL;
#elif Futile_LINUX
	return new XFullScreenWindow();
#elif Futile_WIN32
	/* return a windows window */
	return NULL;
#else
# error build platform is not supported
	return NULL;
#endif
}

}
