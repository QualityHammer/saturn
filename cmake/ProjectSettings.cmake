# Set a default build type
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS
    "Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE
    RelWithDebInfo
    CACHE STRING "Choose the type of build." FORCE)
  # Set build type values for cmake-gui and ccmake
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "release" "MinSizeRel" "RelWithDebInfo")
endif()

# Search for ccache
find_program(CCACHE ccache)
if (CCACHE)
  message("using ccache")
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
else()
  message("ccache not found")
endif()

# Generate compile_commands.json for clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Change executable output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

