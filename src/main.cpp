#include "render/glfwInit.hpp"
#include "common/logging/log.hpp"

int main(int argc, char* argv[]) {
  Log::initLogger();
  Render::renderInit();
  return 0;
}
