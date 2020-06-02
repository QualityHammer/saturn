#include "rasterizer.hpp"

#include <ft2build.h>
#include FT_FREETYPE_H

#include "common/logging/log.hpp"

namespace {

FT_Library library;
FT_Face face;

}// namespace

namespace Rasterize {

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

Map<char, Character> rasterizeFont() {
  Map<char, Character> characters {};
  if (face == nullptr) {
    LOG_ERROR(FreeType, "Font could not be rasterized, as no font is loaded.");
    return characters;
  }
  // ASCII characters as test
  for (unsigned char c {0}; c < 128; ++c) {
    if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
      LOG_ERROR(FreeType, "Failed to load glyph: {}", c);
      continue;
    }
    Character character {0,
      Array<int, 2> {static_cast<int>(face->glyph->bitmap.width), static_cast<int>(face->glyph->bitmap.rows)},
      Array<int, 2> {face->glyph->bitmap_left, face->glyph->bitmap_top},
      static_cast<u32>(face->glyph->advance.x)};
    characters.insert(std::pair<char, Character>(c, character));
  }
  LOG_DEBUG(FreeType, "All characters have been rasterized.");
  return characters;
}

}// namespace Rasterize
