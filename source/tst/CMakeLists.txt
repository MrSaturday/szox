add_subdirectory(gtest)
include_directories ("gtest/include")
include_directories("${PROJECT_SOURCE_DIR}/inc")
include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(ut NDArray_test.cc ExceptionModel_test.cc)
target_link_libraries(ut LINK_PUBLIC gtest_main)

add_custom_target(run_uts
                  COMMAND ut --gtest_color=yes
                  DEPENDS ut
                  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
                 )
