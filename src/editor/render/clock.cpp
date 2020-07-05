#include "clock.hpp"

#include <chrono>
#include <thread>

#include "common/logging/log.hpp"
#include "renderMain.hpp"

namespace Saturn {

Clock::Clock(const u16 fps) :
  m_lastTime {0},
  m_currentTime {0},
  m_fps {static_cast<double>(fps)},
  m_frameLength {1.0 / m_fps} {
  LOG_DEBUG(Clock, "Frame clock created at a speed of {} FPS ({:#02g}ms frame length)", fps, m_frameLength * 1000);
}

bool Clock::shouldRenderFrame() {
  m_currentTime = glfwGetTime();
  const double timeDelta {m_currentTime - m_lastTime};
  if (timeDelta >= m_frameLength) {
    m_lastTime = m_currentTime;
    return true;
  }
  return false;
}

}// namespace Saturn
