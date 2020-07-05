#pragma once

#include "common/types.hpp"

namespace Saturn {

class Clock {
private:
  double m_lastTime;
  double m_currentTime;
  const double m_fps;
  const double m_frameLength;

public:
  Clock(const u16 fps);

  bool shouldRenderFrame();
};

}// namespace Saturn
