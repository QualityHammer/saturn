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

void Window::processInput() {
  if (glfwGetKey(m_mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(m_mainWindow, true);
}

void Window::render() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(m_mainWindow);
}

}// namespace Render
