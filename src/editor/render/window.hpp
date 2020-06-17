#pragma once

#include "common/types.hpp"
#include "common/containerTypes.hpp"
#include "common/character.hpp"
#include "shader.hpp"
#include "frameClock.hpp"

struct GLFWwindow;

namespace Saturn {
namespace Render {

  class Window {
  public:
    Window(const Map<char, Character>& characters);
    ~Window();

    void bindShader() const;
    const Character& getCharacter(const char& c) const;
    const u32& getShaderID() const;
    bool isClosed() const;
    void pollEvents();
    void processInput();
    void render();

    u32 VAO, VBO;
    int t;

  private:
    const Map<char, Character>& m_characters;
    GLFWwindow* m_mainWindow;
    const Shader m_shader;
    FrameClock m_clock;

    GLFWwindow* createWindow();
  };

}// namespace Render
}// namespace Saturn
