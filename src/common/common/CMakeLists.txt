add_subdirectory(logging)

add_library(saturn_common
  ${LOGGING_FILES}
  types.hpp)

target_include_directories(saturn_common
  PUBLIC
  "${CMAKE_SOURCE_DIR}/src/common")

target_link_libraries(saturn_common
  PRIVATE
  project_options
  project_warnings
  PUBLIC
  CONAN_PKG::spdlog
  CONAN_PKG::fmt)
