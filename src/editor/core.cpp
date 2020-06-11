#include "core.hpp"

#include "rasterizer/rasterizer.hpp"
#include "render/renderInit.hpp"
#include "render/loadFont.hpp"

namespace Saturn {

EditorCore::EditorCore() :
  closed {false},
  m_window {},
  m_fontChars {},
  m_shader {"font.vert", "font.frag"} {
  Render::createProjection(m_shader);
  const String font {"test_fonts/DejaVuSans.ttf"};
  Rasterize::initFreeType();
  Rasterize::loadFont(font);
  Rasterize::setFontSize(14);
  Rasterize::loadFont(m_fontChars);
  Render::initAlloc(VAO, VBO);
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
  m_window.render(m_shader, m_fontChars, VAO, VBO);
}

}// namespace Saturn
