// #include "shell/browser/win/ . . . "

#include <dwmapi.h>

#include "base/win/windows_version.h"

namespace {

#define DWMWA_MICA_EFFECT = 1029

enum DWMWINDOWATTRIBUTE {
  DWMWA_USE_IMMERSIVE_DARK_MODE_VALUE = 20,
  DWMWA_MICA_EFFECT_VALUE = 1029
};

enum DWM_BOOL { DWMWCP_FALSE = 0, DWMWCP_TRUE = 1 };

HRESULT TrySetDWMWindowAttribute(HWND hWnd, bool DWMWCP_TRUE) {
  const DWM_BOOL micaPreference = DWMWCP_TRUE;	
  HRESULT result = DwmSetWindowAttribute(hWnd, DWMWA_MICA_EFFECT, &micaPreference, sizeof(micaPreference))

  if (FAILED(result))
  return result;

  auto* os_info = base::win::OSInfo::GetInstance();
  auto const version = os_info->version();


   // MSG msg = {};
   // while (GetMessage(&msg, NULL, 0, 0))

   if (version < base::win::Version::WIN11) {
    HWND activeWindow = GetActiveWindow();
    SendMessage(hWnd, WM_NCACTIVATE, hWnd != activeWindow, 0);
    SendMessage(hWnd, WM_NCACTIVATE, hWnd == activeWindow, 0);
  }
}
  // LRESULT electron browser window ::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
}   // namespace

namespace electron::win {

bool IsMicaSupported() {
  auto* os_info = base::win::OSInfo::GetInstance();
  auto const version = os_info->version();

  return version >= base::win::Version::WIN11_21H2;
}

}  // namespace electron::win