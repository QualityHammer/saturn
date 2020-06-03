add_library(saturn_rasterizer
  rasterizer.hpp
  rasterizer.cpp)

target_link_libraries(saturn_rasterizer
  PRIVATE
  CONAN_PKG::freetype
  project_options
  project_warnings
  saturn_common)

