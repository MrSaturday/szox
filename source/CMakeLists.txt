cmake_minimum_required (VERSION 2.6)
project (szox)

add_subdirectory(tst)

include_directories("inc")
include_directories("src")

add_executable(szox src/szox.cc)
target_compile_features(szox PRIVATE cxx_range_for)
