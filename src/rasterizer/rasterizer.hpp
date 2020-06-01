#pragma once

#include "common/types.hpp"

namespace Rasterize {

void initFreeType();
void loadFont(const String& path);
void setFontSize(const u32 size);

}// namespace Rasterize
