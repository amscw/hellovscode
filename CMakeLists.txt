cmake_minimum_required(VERSION 3.15.3)
project(hello)

set(CMAKE_VERBOSE_MAKEFILE ON)

# Ключи компиляции
add_compile_options(-std=c++17 -Wall -g)

# Заголовочные файлы 
include_directories("M:\\boost_1_79_0")

# Сборка исполняемого файла
add_executable(${PROJECT_NAME}	main.cpp)
