add_library(saturn_rasterizer
  rasterizer.hpp
  rasterizer.cpp)

target_link_libraries(saturn_rasterizer
  PUBLIC
  CONAN_PKG::freetype
  PRIVATE
  project_options
  project_warnings
  saturn_common)

