#pragma once

#include "render/window.hpp"

namespace Saturn {

class EditorCore
{
public:
  EditorCore();
  ~EditorCore();

  void events();
  void render();

  bool closed;

private:
  Render::Window m_window;
};

}// namespace Saturn
