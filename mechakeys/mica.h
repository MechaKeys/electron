#ifndef ELECTRON_SHELL_BROWSER_WIN_MICA_H_
#define ELECTRON_SHELL_BROWSER_WIN_MICA_H_

#include <Windows.h>

namespace electron::win {

bool IsMicaSupported();
void TrySetDWMWindowAttribute(HWND hWnd);

}  // namespace electron::win

#endif  // ELECTRON_SHELL_BROWSER_WIN_MICA_H_
