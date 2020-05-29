#include "common/logging/log.hpp"
#include "glfwInit.hpp"

namespace Render {

void renderInit() {
  if (!glfwInit()) {
    LOG_CRITICAL(GLFW, "GLFW init failed");
  }
}

}// namespace Render

