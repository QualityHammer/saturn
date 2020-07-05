#include "core.hpp"

#include "rasterizer/rasterizer.hpp"
#include "render/renderInit.hpp"
#include "render/loadFont.hpp"

namespace Saturn {

EditorCore::EditorCore() :
  closed {false},
  fontPath {"test_fonts/DejaVuSans.ttf"},
  m_fontChars {},
  m_window {m_fontChars},
  m_clock {60} {
  Rasterize::loadFont(fontPath, 14, m_fontChars);
}

EditorCore::~EditorCore() {
  Render::deleteCharacterTextures(m_fontChars);
}

void EditorCore::events() {
  m_window.pollEvents();
  m_window.processInput();
  if (m_window.isClosed())
    closed = true;
}

void EditorCore::render() {
  if (m_clock.shouldRenderFrame())
    m_window.render();
}

}// namespace Saturn
