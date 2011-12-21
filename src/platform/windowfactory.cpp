#include "platform/windowfactory.h"

#if defined (__GNUC__)
# include "xwindow.h"
# include "xfullscreenwindow.h"
#endif

namespace futile {

WindowFactory::~WindowFactory() { }

Window * WindowFactory::create_window(const Dimension2D & dim)
{
#if defined (__APPLE__)
	/* return a cocoa window */
	return NULL;
#elif defined (__GNUC__)
	return new XWindow(dim);
#elif defined (__WIN32__) || defined (WIN32) || defined (__MINGW32__)
	/* return a windows window */
	return NULL;
#else
# error build platform is not supported
	return NULL;
#endif
}

Window * WindowFactory::create_fullscreen_window()
{
#if defined (__APPLE__)
	/* return a cocoa window */
	return NULL;
#elif defined (__GNUC__)
	return new XFullScreenWindow();
#elif defined (__WIN32__) || defined (WIN32) || defined (__MINGW32__)
	/* return a windows window */
	return NULL;
#else
# error build platform is not supported
	return NULL;
#endif
}

}
