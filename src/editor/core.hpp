#pragma once

#include "common/character.hpp"
#include "common/containerTypes.hpp"
#include "render/shader.hpp"
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
  Map<char, Character> m_fontChars;
  Render::Shader m_shader;
  unsigned int VAO, VBO;
};

}// namespace Saturn
