#pragma once

struct GLFWwindow;

namespace Render {

class Window
{
public:
  Window();
  ~Window();

private:
  GLFWwindow* m_mainWindow;
};

}// namespace Render
