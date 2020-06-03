#pragma once

#include "../render/window.hpp"

namespace Core {

class Core
{
public:
  Core();
  ~Core();

  void run();

private:
  Render::Window m_window;
};

}// namespace Core
