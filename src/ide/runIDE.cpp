#include "runIDE.hpp"

#include "core.hpp"
#include "common/logging/log.hpp"

namespace Saturn {

void runIDE() {
  IDECore core {};
  while (!core.closed) {
    core.events();
    core.render();
  }
}

}// namespace Saturn
