#include "common/logging/log.hpp"
#include "glfwInit.hpp"

namespace Render {

void renderInit() {
  if (!glfwInit()) {
    LOG_INFO(GLFW, "GLFW init failed");
  } else {
    LOG_INFO(GLFW, "GLFW init successful");
  }
}

}// namespace Render

