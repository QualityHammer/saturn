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
  void swapBuffers();

private:
  GLFWwindow* m_mainWindow;
};

}// namespace Render
