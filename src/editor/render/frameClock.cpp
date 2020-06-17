#include "frameClock.hpp"

#include <chrono>
#include <thread>

#include "common/logging/log.hpp"
#include "renderMain.hpp"

namespace Saturn {
namespace Render {

  FrameClock::FrameClock(const u16 fps) :
    m_lastFrame {0},
    m_currentFrame {0},
    m_fps {static_cast<double>(fps)},
    m_frameLength {1.0 / m_fps} {
    LOG_DEBUG(FrameClock, "Frame clock created at a speed of {} FPS ({:#02g}ms frame length)", fps, m_frameLength * 1000);
  }

  bool FrameClock::shouldRenderFrame() {
    m_currentFrame = glfwGetTime();
    const double frameDelta {m_currentFrame - m_lastFrame};
    if (frameDelta >= m_frameLength) {
      m_lastFrame = m_currentFrame;
      return true;
    } else if (frameDelta > (m_frameLength / 2.0))
      std::this_thread::sleep_for(std::chrono::milliseconds {static_cast<u64>(m_frameLength / 2.0 * 1000.0)});
    else
      std::this_thread::sleep_for(std::chrono::milliseconds {static_cast<u64>(frameDelta * 1000.0)});
    return false;
  }

}// namespace Render
}// namespace Saturn
