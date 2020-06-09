#pragma once

struct GLFWwindow;

namespace Render {

class Window
{
public:
  Window();
  ~Window();

  bool isClosed() const;
  void pollEvents();
  void processInput();
  void render();

private:
  GLFWwindow* m_mainWindow;
};

}// namespace Render
