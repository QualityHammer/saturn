#include "window.hpp"

#include "common/logging/log.hpp"
#include "renderMain.hpp"
#include "renderInit.hpp"
#include "glfwCallbacks.hpp"

namespace Render {

Window::Window() {
  renderInit();
  m_mainWindow = glfwCreateWindow(800, 600, "saturn", NULL, NULL);
  if (m_mainWindow == nullptr) {
    LOG_CRITICAL(GLFW, "Failed to create GLFW window");
    glfwTerminate();
  } else {
    glfwMakeContextCurrent(m_mainWindow);
    glfwSetFramebufferSizeCallback(m_mainWindow, Callbacks::framebuffer_size_callback);
  }
}

Window::~Window() {
  glfwTerminate();
}

bool Window::isClosed() const {
  return glfwWindowShouldClose(m_mainWindow);
}

void Window::pollEvents() {
  glfwPollEvents();
}

void Window::swapBuffers() {
  glfwSwapBuffers(m_mainWindow);
}

}// namespace Render
