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

}// namespace Rasterize
