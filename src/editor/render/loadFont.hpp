#pragma once

#include "common/character.hpp"
#include "common/containerTypes.hpp"

namespace Saturn {
namespace Rasterize {

  int loadFont(const String& fontPath, const u16 fontSize, Map<char, Character>& characters);

}// namespace Rasterize

namespace Render {

  void deleteCharacterTextures(Map<char, Character>& characters);

}
}// namespace Saturn
