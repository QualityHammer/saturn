#include "loadFont.hpp"

#include "common/types.hpp"
#include "common/logging/log.hpp"
#include "renderMain.hpp"
#include "../rasterizer/rasterizer.hpp"

namespace Saturn {
namespace Rasterize {

  int loadFont(Map<char, Character>& characters) {
    for (unsigned char c {0}; c < 128; ++c) {
      FT_GlyphSlot glyph;
      int success {rasterizeChar(c, glyph)};
      switch (success) {
      case 1:
        return 1;
      default:
        break;
      };
      unsigned int texture;
      glGenTextures(1, &texture);
      glBindTexture(GL_TEXTURE_2D, texture);
      glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RED,
        glyph->bitmap.width,
        glyph->bitmap.rows,
        0,
        GL_RED,
        GL_UNSIGNED_BYTE,
        glyph->bitmap.buffer);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      Character character {
        texture,
        Array<int, 2> {static_cast<int>(glyph->bitmap.width), static_cast<int>(glyph->bitmap.rows)},
        Array<int, 2> {glyph->bitmap_left, glyph->bitmap_top},
        static_cast<u32>(glyph->advance.x)};
      characters.insert(std::pair<char, Character>(c, character));
    }
    LOG_DEBUG(FreeType, "All characters have been rasterized");
    return 0;
  }

}// namespace Rasterize
}// namespace Saturn

