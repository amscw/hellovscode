cmake_minimum_required(VERSION 3.15.3)
project(hello)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/mingw64.cmake)

# Ключи компиляции
add_compile_options(-std=c++17 -Wall -g)

# Сборка исполняемого файла
add_executable(${PROJECT_NAME}	main.cpp)
