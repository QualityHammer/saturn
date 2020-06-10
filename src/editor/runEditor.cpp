#include "runEditor.hpp"

#include "core.hpp"
#include "common/logging/log.hpp"

namespace Saturn {

void runEditor() {
  EditorCore core {};
  while (!core.closed) {
    core.events();
    core.render();
  }
}

}// namespace Saturn
