#include <unistd.h>

#include "render/glfwInit.hpp"
#include "common/logging/log.hpp"

int main(int argc, char* argv[]) {
  int opt;
  bool verbose {false};
  while ((opt = getopt(argc, argv, "v")) != -1) {
    switch (opt) {
    case 'v':
      verbose = true;
      break;
    default:
      break;
    }
  }

  Log::initLogger(verbose);
  Render::renderInit();
  Log::shutdownLogger();
  return 0;
}
