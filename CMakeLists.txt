# CMakeList.txt : CMake project for ConsoleAbacus, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ConsoleAbacus")

## Add sources
file(GLOB SOURCES "src/*.cpp")

## Add includes
include_directories(include)

## Add dependency
add_subdirectory(external/fmt)

# Add project's executable.
add_executable (ConsoleAbacus ${SOURCES})

# Link dependencies
target_link_libraries(ConsoleAbacus fmt)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConsoleAbacus PROPERTY CXX_STANDARD 17)
endif()

# TODO: Add tests and install targets if needed.
