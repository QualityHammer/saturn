#include "rasterizer.hpp"

#include <ft2build.h>
#include FT_FREETYPE_H

#include "common/logging/log.hpp"

namespace {

FT_Library library;
FT_Face face;

}// namespace

namespace Saturn {
namespace Rasterize {

  void freeFreeType() {
    if (face)
      FT_Done_Face(face);
    FT_Done_FreeType(library);
  }

  void initFreeType() {
    if (FT_Init_FreeType(&library))
      LOG_CRITICAL(FreeType, "An error occurred during library initialization.");
    else
      LOG_DEBUG(FreeType, "FreeType initialization successful.");
  }

  int loadFontFace(const String& fontPath) {
    int errCode {FT_New_Face(library, fontPath.c_str(), 0, &face)};
    if (errCode == FT_Err_Unknown_File_Format) {
      LOG_ERROR(FreeType, "Font file is unsupported by FreeType: {}", fontPath);
      return 1;
    } else if (errCode) {
      LOG_ERROR(FreeType, "Font file could not be read: {}", fontPath);
      return 2;
    }
    LOG_DEBUG(FreeType, "Font file successfully loaded: {}", fontPath);
    return 0;
  }

  int setFontSize(const u32 size) {
    if (!face) {
      LOG_ERROR(FreeType, "Font size {} cannot be set, as no font is loaded", size);
      return 1;
    }

    FT_Set_Pixel_Sizes(face, 0, size);
    LOG_DEBUG(FreeType, "Font size set to {}.", size);
    return 0;
  }

  int rasterizeChar(unsigned char c, RasterizedGlyph& glyph) {
    if (!face) {
      LOG_ERROR(FreeType, "Character {} cannot be rasterized, as no font is loaded", c);
      return 1;
    }

    if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
      LOG_ERROR(FreeType, "Failed to load glyph: {}", c);
      return 2;
    }

    glyph.width = face->glyph->bitmap.width;
    glyph.rows  = face->glyph->bitmap.rows;
    size_t bufLen {static_cast<size_t>(glyph.width * glyph.rows)};
    glyph.left     = face->glyph->bitmap_left;
    glyph.top      = face->glyph->bitmap_top;
    glyph.advancex = face->glyph->advance.x >> 6;
    glyph.buffer   = std::make_unique<unsigned char[]>(bufLen);
    for (u32 h {0}; h < glyph.rows; ++h) {
      for (u32 w {0}; w < glyph.width; ++w) {
        glyph.buffer[h * glyph.width + w] = face->glyph->bitmap.buffer[h * static_cast<u32>(face->glyph->bitmap.pitch) + w];
      }
    }
    LOG_TRACE(FreeType, "Char: {}, w:{}, h:{}, t:{}, l:{}, ax:{}, blen:{}", c, glyph.width, glyph.rows, glyph.top, glyph.left, glyph.advancex, bufLen);
    return 0;
  }

}// namespace Rasterize
}// namespace Saturn
