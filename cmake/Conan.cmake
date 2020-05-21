macro(run_conan)
  # Downloads cmake file automatically
  if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS
      "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
      "${CMAKE_BINARY_DIR}/conan.cmake")
  endif()

  include(${CMAKE_BINARY_DIR}/conan.cmake)

  conan_add_remote(NAME bincrafters URL
                 https://api.bintray.com/conan/bincrafters/public-conan)

  conan_cmake_run(
    REQUIRES
    catch2/2.12.1
    fmt/6.2.0
    OPTIONS
    BASIC_SETUP
    CMAKE_TARGETS
    BUILD
    missing)
endmacro()

