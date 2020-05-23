#include "../logging/logging.hpp"
#include "glfwInit.hpp"

namespace Render {

void renderInit() {
  if (!glfwInit()) {
    Logging::logErr("glfw init failed.");
  }
}

}// namespace Render

