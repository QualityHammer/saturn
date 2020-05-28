add_subdirectory(common/common)
add_subdirectory(render)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  project_options
  project_warnings
  saturn_render
  saturn_common)
