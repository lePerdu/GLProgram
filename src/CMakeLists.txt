#
# src/CMakeLists.txt
#
# Copyright (c) 2016 Zach Peltzer.
# Subject to the MIT License
#

include_directories(".")

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.hpp")

add_library(${GLPROG_LIBRARY} SHARED "${SOURCES}" "${HEADERS}")
target_link_libraries(${GLPROG_LIBRARY}
    "GL"
    "GLEW")

install(TARGETS ${GLPROG_LIBRARY} DESTINATION "lib")
install(FILES ${HEADERS} DESTINATION "include/${GLPROG}")

