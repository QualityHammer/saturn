#pragma once

#include "common/types.hpp"

namespace Saturn {
namespace Render {

  class Shader
  {
  public:
    Shader(const String& vertexPath, const String& fragmentPath);
    ~Shader();

    void bind() const;

    unsigned int ID;

  private:
    void checkCompileErrors(u32 shader, String type);
  };

}// namespace Render
}// namespace Saturn
