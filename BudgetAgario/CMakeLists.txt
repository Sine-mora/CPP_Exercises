CMAKE_MINIMUM_REQUIRED(VERSION 3.7.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify C++17 as the standard
set_property(TARGET ${BINARY} PROPERTY CXX_STANDARD 14)

project(Hello-World)
message(${PROJECT_NAME})
message(${PROJECT_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})

set(BINARY "CPP-Course-exe")
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)
message(${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})
message(${src_dir})

MACRO(SOURCE_FILES return_list curr_dir)
    FILE(GLOB_RECURSE new_list ${curr_dir}/*.h ${curr_dir}/*.cpp ${curr_dir}/*.hpp ${curr_dir}/*.inl)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        message(STATUS "[INFO] file_path: ${file_path}")
        SET(dir_list ${dir_list} ${file_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

SOURCE_FILES(src_files ${src_dir})

message(STATUS ${src_files})
add_compile_options(-Wall -Wextra -pedantic -Werror)
add_executable(${BINARY} ${src_files})

INCLUDE(FindPkgConfig)

#PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

find_file(SDL2_INCLUDE_DIRS NAME SDL.h HINTS SDL2)
find_library(SDL2_LIBRARIES NAME SDL2)

find_file(SDL2IMAGE_INCLUDE_DIRS NAME SDL.h HINTS SDL2)
find_library(SDL2IMAGE_LIBRARIES NAME SDL2_image)


target_include_directories(${BINARY} PUBLIC ${src_dir} ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

target_link_libraries(${BINARY} PUBLIC pugixml ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

message(STATUS "Cmake build type = ${CMAKE_BUILD_TYPE}")
