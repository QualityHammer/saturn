#include "core.hpp"

#include "rasterizer/rasterizer.hpp"
#include "render/renderInit.hpp"
#include "render/loadFont.hpp"

namespace Saturn {

IDECore::IDECore() :
  closed {false},
  fontPath {"test_fonts/DejaVuSans.ttf"},
  m_fontChars {},
  m_window {m_fontChars},
  m_clock {60} {
  Rasterize::loadFont(fontPath, 14, m_fontChars);
}

IDECore::~IDECore() {
  Render::deleteCharacterTextures(m_fontChars);
}

void IDECore::events() {
  m_window.pollEvents();
  m_window.processInput();
  if (m_window.isClosed())
    closed = true;
}

void IDECore::render() {
  if (m_clock.shouldRenderFrame())
    m_window.render();
}

}// namespace Saturn
