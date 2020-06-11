#pragma once

#include <memory>

#include "common/types.hpp"
#include "common/character.hpp"
#include "common/containerTypes.hpp"

namespace Saturn {
namespace Rasterize {

  struct RasterizedGlyph {
    u32 width, rows;
    s32 left, top;
    std::unique_ptr<unsigned char[]> buffer;
    s64 advancex;
  };

  void freeFreeType();
  void initFreeType();
  int loadFontFace(const String& fontPath);
  int setFontSize(const u32 size);
  int rasterizeChar(unsigned char c, RasterizedGlyph& glyph);

}// namespace Rasterize
}// namespace Saturn
