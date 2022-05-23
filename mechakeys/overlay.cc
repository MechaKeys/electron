#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <Windows.h>

#include "mechakeys/overlay_win64.h"

namespace mechakeys {

struct Overlay {
  uint32_t pid;
};

struct OverlayFrameDimensions {
  int32_t windowWidth;
  int32_t windowHeight;
};

struct OverlayFrameCoordinates {
  int32_t window_X;
  int32_t window_Y;
  int32_t window_center;
};

}  // namespace mechakeys