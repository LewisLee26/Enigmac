cmake_minimum_required(VERSION 3.18)
set(PYTHON_EXECUTABLE "C:/Users/lewis/anaconda3/python.exe")
project(enigmacpp)

# Set the source files for enigmacpp target
set(ENIGMA_SOURCE_FILES
    src/enigma.cpp
    src/connector.cpp
    src/rotor.cpp
    src/plugboard.cpp
)

# Create the enigma library target
add_library(enigma STATIC ${ENIGMA_SOURCE_FILES})
set_target_properties(enigma PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Add the pybind11 subdirectory
add_subdirectory(pybind11)

# Create the enigmacpp module target
pybind11_add_module(enigmacpp src/binder.cpp)

# Link the enigmacpp module with enigmacpp library
target_link_libraries(enigmacpp PRIVATE enigma)