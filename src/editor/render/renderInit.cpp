#include "renderInit.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "common/logging/log.hpp"
#include "glLog.hpp"
#include "renderMain.hpp"

namespace Saturn {
namespace Render {

  void gladInit() {
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
      LOG_CRITICAL(GLAD, "Failed to initialize GLAD");
      return;
    }
    LOG_DEBUG(GLAD, "GLAD init successful");
    glViewport(0, 0, 1600, 1200);
    LOG_GL();

    // disable byte-alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    LOG_GL();
    // disable depth test
    glDisable(GL_DEPTH_TEST);
    LOG_GL();
    // enable blending
    glEnable(GL_BLEND);
    LOG_GL();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    LOG_GL();
  }

  void createProjection(const Shader& shader) {
    glm::mat4 projection {glm::ortho(0.0f, 800.0f, 0.0f, 600.0f)};
    shader.use();
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    LOG_GL();
  }

  void initAlloc(unsigned int& VAO, unsigned int& VBO) {
    glGenVertexArrays(1, &VAO);
    LOG_GL();
    glGenBuffers(1, &VBO);
    LOG_GL();
    glBindVertexArray(VAO);
    LOG_GL();
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    LOG_GL();
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    LOG_GL();
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    LOG_GL();
    glEnableVertexAttribArray(0);
    LOG_GL();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    LOG_GL();
    glBindVertexArray(0);
    LOG_GL();
  }

  void renderInit() {
    if (!glfwInit()) {
      LOG_CRITICAL(GLFW, "GLFW init failed");
      return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    LOG_DEBUG(GLFW, "GLFW init successful");
  }

}// namespace Render
}// namespace Saturn

