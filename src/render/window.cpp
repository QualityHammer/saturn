#include "window.hpp"

#include "common/logging/log.hpp"
#include "renderMain.hpp"
#include "glfwCallbacks.hpp"

namespace Render {

Window::Window() {
  m_mainWindow = glfwCreateWindow(800, 600, "saturn", NULL, NULL);
  if (m_mainWindow == nullptr) {
    LOG_CRITICAL(GLFW, "Failed to create GLFW window");
    glfwTerminate();
  } else
    glfwMakeContextCurrent(m_mainWindow);

  glfwSetFramebufferSizeCallback(m_mainWindow, Callbacks::framebuffer_size_callback);
}

Window::~Window() {}

}// namespace Render
