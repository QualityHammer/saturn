#pragma once

#include "common/types.hpp"
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
  String fontPath;

private:
  Map<char, Character> m_fontChars;
  Render::Window m_window;
  Render::Shader m_shader;
  unsigned int VAO, VBO;
};

}// namespace Saturn
