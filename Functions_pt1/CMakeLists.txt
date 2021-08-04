CMAKE_MINIMUM_REQUIRED(VERSION 3.7.2)

project(Functions_pt1)
message(${PROJECT_NAME})
message(${PROJECT_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})

set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)
message(${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})
message(${src_dir})


file(GLOB src_files ${src_dir}/*.cpp ${src_dir}/*.h)

add_compile_options(-Wall -Wextra -pedantic -Werror)
add_executable(Functions_pt1-exe  ${src_files})

target_include_directories(Functions_pt1-exe PUBLIC ../Library)

target_link_libraries(Functions_pt1-exe PUBLIC pugixml)

message(STATUS "Cmake build type = ${CMAKE_BUILD_TYPE}")
