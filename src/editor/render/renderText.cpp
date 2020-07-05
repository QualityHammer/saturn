#include "renderText.hpp"

#include "common/character.hpp"
#include "common/types.hpp"
#include "glLog.hpp"
#include "window.hpp"
#include "renderMain.hpp"

namespace Saturn {
namespace Render {

  void renderText(const Window& window, const String& text, u16 x, u16 y, float scale) {
    window.bindShader();
    glUniform3f(glGetUniformLocation(window.getShaderID(), "textColor"), 0.0f, 0.0f, 0.0f);
    LOG_GL();
    glActiveTexture(GL_TEXTURE0);
    LOG_GL();
    glBindVertexArray(window.VAO);
    LOG_GL();

    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++) {
      const Character& ch {window.getCharacter(*c)};

      const float xPos {static_cast<float>((x + ch.bearing[0])) * scale};
      const float yPos {static_cast<float>(y + ch.size[1] - static_cast<u32>(ch.bearing[1])) * scale};
      const float w {static_cast<float>(ch.size[0]) * scale};
      const float h {static_cast<float>(ch.size[1]) * scale};
      const float vertices[6][4] = {
        {xPos, yPos + h, 0.0f, 0.0f},
        {xPos, yPos, 0.0f, 1.0f},
        {xPos + w, yPos, 1.0f, 1.0f},
        {xPos, yPos + h, 0.0f, 0.0f},
        {xPos + w, yPos, 1.0f, 1.0f},
        {xPos + w, yPos + h, 1.0f, 0.0f}};
      glBindTexture(GL_TEXTURE_2D, ch.textureID);
      LOG_GL();
      glBindBuffer(GL_ARRAY_BUFFER, window.VBO);
      LOG_GL();
      glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
      LOG_GL();
      glBindBuffer(GL_ARRAY_BUFFER, 0);
      LOG_GL();
      glDrawArrays(GL_TRIANGLES, 0, 6);
      LOG_GL();
      x += static_cast<u16>(ch.offset);
    }
    glBindVertexArray(0);
    LOG_GL();
    glBindTexture(GL_TEXTURE_2D, 0);
    LOG_GL();
  }

}// namespace Render
}// namespace Saturn
