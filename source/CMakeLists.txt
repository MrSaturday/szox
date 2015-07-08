cmake_minimum_required (VERSION 2.6)
project (szox)

### project directories
set(SZOX_CORE_DIR core)
set(GTEST_DIR 3rdparty/gtest)

### project source files
file(GLOB   UT_CORE_FILES     core/tst/*.cc)
file(GLOB   SZOX_CORE_FILES   core/src/*.cc)

### include paths
include_directories ( ${GTEST_DIR}/include
                      ${SZOX_CORE_DIR}/inc
                    )

### subprojects / libraries
add_subdirectory ( ${GTEST_DIR} )

### main target
add_executable(szox
               szox.cc
               ${SZOX_CORE_FILES} 
              )

### unit tests
add_executable(ut
               ${SZOX_CORE_FILES}
               ${UT_CORE_FILES}
              )

target_link_libraries(ut gtest_main)

add_custom_target(run_uts
                  COMMAND ut --gtest_color=yes
                  DEPENDS ut
                  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
                 )
