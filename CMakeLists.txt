cmake_minimum_required(VERSION 3.24)
project(grep-lite LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_ASAN "Enable Address/UB sanitizers" ON)
if (ENABLE_ASAN AND CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

add_library(greplite
    src/parse_parameters.cpp
)
target_include_directories(greplite PUBLIC include)
add_executable(grep-lite src/main.cpp)
target_link_libraries(grep-lite PRIVATE greplite)
