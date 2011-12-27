#include <futile/platform/windowfactory.h>

#if Futile_APPLE
# include "apple/window.h"
# include "apple/fullscreenwindow.h"
# include "apple/windowedwindow.h"
#elif Futile_LINUX
# include "linux/window.h"
# include "linux/fullscreenwindow.h"
# include "linux/windowedwindow.h"
#elif Futile_WIN32
# include "win32/window.h"
# include "win32/fullscreenwindow.h"
# include "win32/windowedwindow.h"
#endif

namespace futile {

WindowFactory::~WindowFactory() { }

Windowable * WindowFactory::create_window(GraphicsContext * gfxctx)
{
	return new WindowedWindow(gfxctx);
}

Windowable * WindowFactory::create_fullscreen_window(GraphicsContext * gfxctx)
{
	return new FullScreenWindow(gfxctx);
}

}
