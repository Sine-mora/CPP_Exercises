CMAKE_MINIMUM_REQUIRED(VERSION 3.7.2)

project(Exercise2)
message(${PROJECT_NAME})
message(${PROJECT_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})

set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)
message(${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})
message(${src_dir})


file(GLOB src_files ${src_dir}/*.cpp ${src_dir}/*.h)

add_compile_options(-Wall -Wextra -pedantic -Werror)
add_executable(Exercise2-exe  ${src_files})

message(STATUS "Cmake build type = ${CMAKE_BUILD_TYPE}")
