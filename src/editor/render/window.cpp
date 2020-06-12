#include "window.hpp"

#include "common/logging/log.hpp"
#include "glLog.hpp"
#include "renderMain.hpp"
#include "renderInit.hpp"
#include "glfwCallbacks.hpp"
#include "renderText.hpp"

namespace Saturn {
namespace Render {

  Window::Window(const Map<char, Character>& characters) :
    m_characters {characters},
    m_mainWindow {createWindow()},
    m_shader {"font.vert", "font.frag"} {
    createProjection(m_shader);
  }

  Window::~Window() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwDestroyWindow(m_mainWindow);
    m_mainWindow = nullptr;
    glfwTerminate();
  }

  void Window::bindShader() const {
    m_shader.use();
  }

  GLFWwindow* Window::createWindow() {
    renderInit();
    GLFWwindow* win {glfwCreateWindow(800, 600, "saturn", NULL, NULL)};
    if (win == nullptr) {
      LOG_CRITICAL(GLFW, "Failed to create GLFW window");
      glfwTerminate();
    } else {
      glfwMakeContextCurrent(win);
      glfwSetFramebufferSizeCallback(win, Callbacks::framebuffer_size_callback);
      gladInit();
      initAlloc(VAO, VBO);
    }
    return win;
  }

  const Character& Window::getCharacter(const char& c) const {
    return m_characters.at(c);
  }

  const u32& Window::getShaderID() const {
    return m_shader.ID;
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
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    LOG_GL();

    const String text {"Hello this is a test"};
    renderText(*this, text, 30, 200, 1.0);

    glfwSwapBuffers(m_mainWindow);
  }

}// namespace Render
}// namespace Saturn
