#include "window.hpp"

#include "common/logging/log.hpp"
#include "glLog.hpp"
#include "renderMain.hpp"
#include "renderInit.hpp"
#include "glfwCallbacks.hpp"

namespace Saturn {
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
      gladInit();
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

  void Window::render(Shader& shader, Map<char, Character>& characters, unsigned int VAO, unsigned int VBO) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    LOG_GL();

    shader.use();
    glUniform3f(glGetUniformLocation(shader.ID, "textColor"), 0.0f, 0.0f, 0.0f);
    LOG_GL();
    glActiveTexture(GL_TEXTURE0);
    LOG_GL();
    glBindVertexArray(VAO);
    LOG_GL();

    int x {0};
    const String text {"thisistest"};
    const u32 scale {1};
    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++) {
      const Character& ch {characters[*c]};

      float xPos {static_cast<float>((700 + x + ch.bearing[0]) * static_cast<int>(scale))};
      float yPos {static_cast<float>((500 + ch.size[1] - static_cast<u32>(ch.bearing[1])) * scale)};
      float w {static_cast<float>(ch.size[0] * scale)};
      float h {static_cast<float>(ch.size[1] * scale)};
      float vertices[6][4] = {
        {xPos, yPos + h, 0.0f, 0.0f},
        {xPos, yPos, 0.0f, 1.0f},
        {xPos + w, yPos, 1.0f, 1.0f},
        {xPos, yPos + h, 0.0f, 0.0f},
        {xPos + w, yPos, 1.0f, 1.0f},
        {xPos + w, yPos + h, 1.0f, 0.0f}};
      glBindTexture(GL_TEXTURE_2D, ch.textureID);
      LOG_GL();
      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      LOG_GL();
      glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
      LOG_GL();
      glBindBuffer(GL_ARRAY_BUFFER, 0);
      LOG_GL();
      glDrawArrays(GL_TRIANGLES, 0, 6);
      LOG_GL();
      x += static_cast<int>(ch.offset);
    }
    glBindVertexArray(0);
    LOG_GL();
    glBindTexture(GL_TEXTURE_2D, 0);
    LOG_GL();

    glfwSwapBuffers(m_mainWindow);
  }

}// namespace Render
}// namespace Saturn
