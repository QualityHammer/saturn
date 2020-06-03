#include "glfwCallbacks.hpp"

#include "renderMain.hpp"

namespace Callbacks {

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

}// namespace Callbacks
