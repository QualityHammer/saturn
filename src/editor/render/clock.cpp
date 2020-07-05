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
  } else if (timeDelta > (m_frameLength / 2.0))
    std::this_thread::sleep_for(std::chrono::milliseconds {static_cast<u64>(m_frameLength / 2.0 * 1000.0)});
  else
    std::this_thread::sleep_for(std::chrono::milliseconds {static_cast<u64>(timeDelta * 1000.0)});
  return false;
}

}// namespace Saturn
