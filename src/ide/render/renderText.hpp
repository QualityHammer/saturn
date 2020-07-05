#pragma once

#include "common/types.hpp"

namespace Saturn {
namespace Render {

  class Window;

  void renderText(const Window& window, const String& text, u16 x, u16 y, float scale);

}// namespace Render
}// namespace Saturn
