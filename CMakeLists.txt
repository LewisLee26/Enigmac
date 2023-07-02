cmake_minimum_required(VERSION 3.4...3.18)
project(enigmacpp)

add_library(enigma STATIC src/enigma.cpp)
set_target_properties(enigma PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_subdirectory(pybind11)
pybind11_add_module(enigmacpp src/binder.cpp)
target_link_libraries(enigmacpp PRIVATE enigmacpp)