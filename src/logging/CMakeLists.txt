add_library(saturn_logging
  logging.hpp
  logging.cpp)

target_link_libraries(saturn_logging
  PRIVATE
  project_options
  project_warnings
  CONAN_PKG::spdlog)
