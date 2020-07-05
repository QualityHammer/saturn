#include "shader.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/glm.hpp>

#include "common/logging/log.hpp"
#include "glLog.hpp"
#include "renderMain.hpp"

namespace Saturn {
namespace Render {

  Shader::Shader(const String& vertexPath, const String& fragmentPath) :
    ID {0} {
    String vertexCode;
    String fragmentCode;
    std::ifstream vFile;
    std::ifstream fFile;
    vFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    const String shaderPath {"shaders/"};
    try {
      vFile.open(shaderPath + vertexPath);
      fFile.open(shaderPath + fragmentPath);
      std::stringstream vStream, fStream;
      vStream << vFile.rdbuf();
      fStream << fFile.rdbuf();
      vFile.close();
      fFile.close();
      vertexCode   = vStream.str();
      fragmentCode = fStream.str();
    } catch (std::ifstream::failure& e) {
      LOG_CRITICAL(OpenGL, "Failed to read shader file");
    }
    const char* vCode {vertexCode.c_str()};
    const char* fCode {fragmentCode.c_str()};
    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    LOG_GL();
    glShaderSource(vertex, 1, &vCode, NULL);
    LOG_GL();
    glCompileShader(vertex);
    LOG_GL();
    checkCompileErrors(vertex, "VERTEX");
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    LOG_GL();
    glShaderSource(fragment, 1, &fCode, NULL);
    LOG_GL();
    glCompileShader(fragment);
    LOG_GL();
    checkCompileErrors(fragment, "FRAGMENT");

    ID = glCreateProgram();
    LOG_GL();
    glAttachShader(ID, vertex);
    LOG_GL();
    glAttachShader(ID, fragment);
    LOG_GL();
    glLinkProgram(ID);
    LOG_GL();
    checkCompileErrors(ID, "PROGRAM");
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    LOG_DEBUG(OpenGL, "Shader program created");
  }

  void Shader::bind() const {
    glUseProgram(ID);
  }

  void Shader::checkCompileErrors(u32 shader, String type) {
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM") {
      glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
      if (!success) {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        LOG_CRITICAL(OpenGL, "Shader compilation error of type {}\n{}", type, infoLog);
      }
    } else {
      glGetProgramiv(shader, GL_LINK_STATUS, &success);
      if (!success) {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        LOG_CRITICAL(OpenGL, "Program linking error of type {}\n{}", type, infoLog);
      }
    }
  }

}// namespace Render
}// namespace Saturn
