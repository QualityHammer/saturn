#pragma once

#include "common/types.hpp"
#include "common/containerTypes.hpp"

struct Character {
  u32 textureID;
  Array<int, 2> size;
  Array<int, 2> bearing;
  u32 offset;
};
