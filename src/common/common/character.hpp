#pragma once

#include "common/types.hpp"
#include "common/containerTypes.hpp"

struct Character {
  u32 textureID;
  Array<u32, 2> size;
  Array<s32, 2> bearing;
  s64 offset;
};
