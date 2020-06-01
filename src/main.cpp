#include <unistd.h>

#include "rasterizer/rasterizer.hpp"
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

  const String font {"/Users/ryan/Library/Fonts/DejaVu Sans Mono for Powerline.ttf"};
  Log::initLogger(verbose);
  Rasterize::initFreeType();
  Rasterize::loadFont(font);
  Rasterize::setFontSize(48);
  Render::renderInit();
  Log::shutdownLogger();
  return 0;
}
