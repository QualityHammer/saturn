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
    FT_Done_Face(face);
    FT_Done_FreeType(library);
  }

  void initFreeType() {
    if (FT_Init_FreeType(&library))
      LOG_CRITICAL(FreeType, "An error occurred during library initialization.");
    else
      LOG_DEBUG(FreeType, "FreeType initialization successful.");
  }

  void loadFont(const String& fontPath) {
    int errCode {FT_New_Face(library, fontPath.c_str(), 0, &face)};
    if (errCode == FT_Err_Unknown_File_Format)
      LOG_ERROR(FreeType, "Font file is unsupported by FreeType: {}", fontPath);
    else if (errCode)
      LOG_ERROR(FreeType, "Font file could not be read: {}", fontPath);
    else
      LOG_DEBUG(FreeType, "Font file successfully loaded: {}", fontPath);
  }

  void setFontSize(const u32 size) {
    if (face == nullptr) {
      LOG_ERROR(FreeType, "Font size {} could not be set, as no font is loaded.", size);
      return;
    }
    FT_Set_Pixel_Sizes(face, 0, size);
    LOG_DEBUG(FreeType, "Font size set to {}.", size);
  }

  int rasterizeChar(unsigned char c, RasterizedGlyph& glyph) {
    if (face == nullptr) {
      LOG_ERROR(FreeType, "Font could not be rasterized, as no font is loaded.");
      return 1;
    }
    if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
      LOG_ERROR(FreeType, "Failed to load glyph: {}", c);
      return 2;
    }
    glyph.width    = face->glyph->bitmap.width;
    glyph.rows     = face->glyph->bitmap.rows;
    glyph.left     = face->glyph->bitmap_left;
    glyph.top      = face->glyph->bitmap_top;
    glyph.advancex = face->glyph->advance.x;
    size_t bufLen {static_cast<size_t>(glyph.width * glyph.rows)};
    glyph.buffer = std::make_unique<unsigned char[]>(bufLen);
    for (u32 h {0}; h < glyph.rows; ++h) {
      for (u32 w {0}; w < glyph.width; ++w) {
        glyph.buffer[h * glyph.width + w] = face->glyph->bitmap.buffer[h * face->glyph->bitmap.pitch + w];
      }
    }
    LOG_DEBUG(FreeType, "Char: {}, w:{}, h:{}, t:{}, l:{}, ax:{}, blen:{}", c, glyph.width, glyph.rows, glyph.top, glyph.left, glyph.advancex, bufLen);
    return 0;
  }

}// namespace Rasterize
}// namespace Saturn
