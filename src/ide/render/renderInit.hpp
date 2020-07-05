#pragma once

#include "shader.hpp"

namespace Saturn {
namespace Render {

  void createProjection(const Shader& shader);
  void gladInit();
  void renderInit();
  void initAlloc(unsigned int& VAO, unsigned int& VBO);

}// namespace Render
}// namespace Saturn
