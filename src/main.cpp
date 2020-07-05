#include <unistd.h>

#include "common/logging/log.hpp"
#include "ide/runIDE.hpp"

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
  Saturn::runIDE();
  Log::shutdownLogger();
  return 0;
}
