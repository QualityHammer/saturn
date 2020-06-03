#include "renderInit.hpp"

#include "common/logging/log.hpp"
#include "renderMain.hpp"

namespace Render {

void gladInit() {
  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    LOG_CRITICAL(GLAD, "Failed to initialize GLAD");
  }
  glViewport(0, 0, 800, 600);
}

void renderInit() {
  if (!glfwInit()) {
    LOG_CRITICAL(GLFW, "GLFW init failed");
    return;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  LOG_DEBUG(GLFW, "GLFW init successful");
}

}// namespace Render

