#include "core.hpp"

#include "rasterizer/rasterizer.hpp"
#include "render/renderInit.hpp"

namespace Saturn {

EditorCore::EditorCore() :
  closed {false},
  m_window {} {
  const String font {"test_fonts/DejaVuSans.ttf"};
  Rasterize::initFreeType();
  Rasterize::loadFont(font);
  Rasterize::setFontSize(48);
  Rasterize::rasterizeFont();
  Render::gladInit();
}

EditorCore::~EditorCore() {
}

void EditorCore::events() {
  m_window.pollEvents();
  m_window.processInput();
  if (!m_window.isClosed())
    closed = true;
}

void EditorCore::render() {
  m_window.render();
}

}// namespace Saturn
