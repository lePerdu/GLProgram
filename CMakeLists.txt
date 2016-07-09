#
# CMakeLists.txt
#
# Copyright (c) 2016 Zach Peltzer.
# Subject to the MIT License
#

cmake_minimum_required(VERSION "3.5" FATAL_ERROR)

project("GLProgram"
    VERSION "0.1"
    LANGUAGES "CXX")

set(GLPROG "glprog")
set(GLPROG_LIBRARY "${GLPROG}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")

add_subdirectory("src")

