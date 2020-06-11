#pragma once

#include "common/containerTypes.hpp"
#include "common/character.hpp"
#include "shader.hpp"

struct GLFWwindow;

namespace Saturn {
namespace Render {

  class Window
  {
  public:
    Window();
    ~Window();

    bool isClosed() const;
    void pollEvents();
    void processInput();
    void render(Shader& shader, Map<char, Character>& characters, unsigned int VAO, unsigned int VBO);

  private:
    GLFWwindow* m_mainWindow;
  };

}// namespace Render
}// namespace Saturn
