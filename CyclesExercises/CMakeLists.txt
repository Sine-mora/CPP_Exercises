CMAKE_MINIMUM_REQUIRED(VERSION 3.7.2)

set (CMAKE_CXX_STANDARD 14)
#Specify compilers
if("${CMAKE_C_COMPILER}" STREQUAL "")
set(CMAKE_C_COMPILER gcc CACHE INTERNAL "")
message(STATUS "No C compiler was specified. Setting to ${CMAKE_C_COMPILER}")
endif()
if("${CMAKE_CXX_COMPILER}" STREQUAL "")
set(CMAKE_CXX_COMPILER g++ CACHE INTERNAL "")
message(STATUS "No C++ compiler was specified. Setting to ${CMAKE_CXX_COMPILER}")
endif()


project(CycleTasks)
message(${PROJECT_NAME})
message(${PROJECT_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})

set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)
message(${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})
message(${src_dir})


file(GLOB src_files ${src_dir}/*.cpp ${src_dir}/*.h)

add_compile_options(-Wall -Wextra -pedantic -Werror)
add_executable(CycleTasks-exe  ${src_files})

message(STATUS "Cmake build type = ${CMAKE_BUILD_TYPE}")
