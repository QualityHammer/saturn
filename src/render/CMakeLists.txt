add_library(saturn_render
  glfwMain.hpp
  glfwInit.hpp
  glfwInit.cpp)

target_link_libraries(saturn_render
  PUBLIC
  glad
  glfw
  PRIVATE
  saturn_common
  project_options
  project_warnings)
