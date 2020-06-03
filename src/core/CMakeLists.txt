add_library(saturn_core
  core.cpp
  core.hpp)

target_link_libraries(saturn_core
  PRIVATE
  project_options
  project_warnings
  saturn_common
  saturn_render
  saturn_rasterizer)
