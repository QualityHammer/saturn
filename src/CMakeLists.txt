add_subdirectory(render)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  saturn_render
  project_options
  project_warnings)
