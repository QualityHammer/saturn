#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include "common/types.hpp"
#include "common/character.hpp"
#include "common/containerTypes.hpp"

namespace Saturn {
namespace Rasterize {

  void initFreeType();
  void loadFont(const String& path);
  void setFontSize(const u32 size);
  int rasterizeChar(unsigned char c, FT_GlyphSlot glyph);

}// namespace Rasterize
}// namespace Saturn
