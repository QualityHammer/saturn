#include "loadFont.hpp"

#include "common/types.hpp"
#include "common/logging/log.hpp"
#include "glLog.hpp"
#include "renderMain.hpp"
#include "../rasterizer/rasterizer.hpp"

namespace Saturn {
namespace Rasterize {

  int loadFont(Map<char, Character>& characters) {
    RasterizedGlyph glyph {};
    for (unsigned char c {0}; c < 128; ++c) {
      int success {rasterizeChar(c, glyph)};
      switch (success) {
      case 1:
        return 1;
      case 2:
        continue;
      default:
        break;
      };
      unsigned int texture;
      glGenTextures(1, &texture);
      LOG_GL();
      glBindTexture(GL_TEXTURE_2D, texture);
      LOG_GL();
      glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RED,
        static_cast<s32>(glyph.width),
        static_cast<s32>(glyph.rows),
        0,
        GL_RED,
        GL_UNSIGNED_BYTE,
        glyph.buffer.get());
      LOG_GL();
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      LOG_GL();
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      LOG_GL();
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      LOG_GL();
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      LOG_GL();
      Character character {
        texture,
        Array<u32, 2> {glyph.width, glyph.rows},
        Array<s32, 2> {glyph.left, glyph.top},
        glyph.advancex};
      characters.insert(std::pair<char, Character>(c, character));
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    LOG_GL();
    freeFreeType();
    LOG_DEBUG(FreeType, "All characters have been rasterized");
    return 0;
  }

}// namespace Rasterize
}// namespace Saturn
