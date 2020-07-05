#pragma once

#include "common/types.hpp"
#include "common/character.hpp"
#include "common/containerTypes.hpp"
#include "render/shader.hpp"
#include "render/window.hpp"
#include "render/clock.hpp"

namespace Saturn {

class IDECore {
public:
  IDECore();
  ~IDECore();

  void events();
  void render();

  bool closed;
  String fontPath;

private:
  Map<char, Character> m_fontChars;
  Render::Window m_window;
  Clock m_clock;
};

}// namespace Saturn
