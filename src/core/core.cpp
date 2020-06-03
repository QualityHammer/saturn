#include "core.hpp"

#include "../rasterizer/rasterizer.hpp"
#include "../render/renderInit.hpp"

namespace Core {

Core::Core() :
  m_window {} {
  const String font {"test_fonts/DejaVuSans.ttf"};
  Rasterize::initFreeType();
  Rasterize::loadFont(font);
  Rasterize::setFontSize(48);
  Rasterize::rasterizeFont();
  Render::gladInit();
}

Core::~Core() {
}

void Core::run() {
  while (!m_window.isClosed()) {
    m_window.processInput();
    m_window.render();
    m_window.pollEvents();
  }
}

}// namespace Core
