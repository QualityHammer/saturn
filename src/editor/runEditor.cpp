#include "runEditor.hpp"

#include "core.hpp"

namespace Saturn {

void runEditor() {
  EditorCore core {};
  while (!core.closed) {
    core.events();
    core.render();
  }
}

}// namespace Saturn
