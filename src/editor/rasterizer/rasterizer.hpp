#pragma once

#include "common/types.hpp"
#include "common/character.hpp"
#include "common/containerTypes.hpp"

namespace Rasterize {

void initFreeType();
void loadFont(const String& path);
void setFontSize(const u32 size);
Map<char, Character> rasterizeFont();

}// namespace Rasterize
