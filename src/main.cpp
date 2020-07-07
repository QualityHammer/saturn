#include <unistd.h>

#include "common/logging/log.hpp"
#include "ide/runIDE.hpp"

struct CMDArgs {
  bool verbose {false};
};

void getArgs(int argc, char* argv[], CMDArgs& cmdArgs) {
  int opt;
  while ((opt = getopt(argc, argv, "v")) != -1) {
    switch (opt) {
    case 'v':
      cmdArgs.verbose = true;
      break;
    default:
      break;
    }
  }
}

int main(int argc, char* argv[]) {
  CMDArgs cmdArgs;
  getArgs(argc, argv, cmdArgs);

  Log::initLogger(cmdArgs.verbose);
  Saturn::runIDE();
  Log::shutdownLogger();
  return 0;
}
