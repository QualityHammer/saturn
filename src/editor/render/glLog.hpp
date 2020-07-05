#pragma once

#include "common/logging/log.hpp"
#include "renderMain.hpp"

#ifdef DEBUG
#define LOG_GL() \
  if (glGetError()) LOG_DEBUG(OpenGL, "GL ErrorCode: {}", glGetError());
#else
#define LOG_GL() (void(0))
#endif
