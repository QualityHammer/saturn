#pragma once

#include "common/types.hpp"

namespace Saturn {
namespace Render {

  class FrameClock {
  private:
    double m_lastFrame;
    double m_currentFrame;
    const double m_fps;
    const double m_frameLength;

  public:
    FrameClock(const u16 fps);

    bool shouldRenderFrame();
  };

}// namespace Render
}// namespace Saturn
