#include "core.hpp"

#include "rasterizer/rasterizer.hpp"
#include "render/renderInit.hpp"
#include "render/loadFont.hpp"

namespace Saturn {

EditorCore::EditorCore() :
  closed {false},
  m_window {},
  m_fontChars {} {
  Render::gladInit();
  const String font {"test_fonts/DejaVuSans.ttf"};
  Rasterize::initFreeType();
  Rasterize::loadFont(font);
  Rasterize::setFontSize(48);
  Rasterize::loadFont(m_fontChars);
}

EditorCore::~EditorCore() {
}

void EditorCore::events() {
  m_window.pollEvents();
  m_window.processInput();
  if (m_window.isClosed())
    closed = true;
}

void EditorCore::render() {
  m_window.render();
}

}// namespace Saturn
