cmake_minimum_required (VERSION 2.6)
project (szox)

add_subdirectory(tst)

include_directories("inc")
include_directories("src")

add_library(szox_core src/NDPoint.cc src/Chain.cc src/DirectionVector.cc)

add_executable(szox src/szox.cc)
target_link_libraries(szox szox_core)

target_compile_features(szox PRIVATE cxx_range_for)

set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )
