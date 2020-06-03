#include <unistd.h>

#include "common/logging/log.hpp"
#include "core/core.hpp"

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
  Core::Core core {};
  core.run();
  Log::shutdownLogger();
  return 0;
}
