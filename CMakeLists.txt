cmake_minimum_required(VERSION 3.6)
project(build_graph)

set(CMAKE_CXX_STANDARD 14)

include(build/conanbuildinfo.cmake)
conan_basic_setup()

set(SOURCE_FILES src/main.cpp src/config/operation_node.hpp src/config/id.hpp src/config/io_node.hpp src/config/operation_node.cpp src/config/graph.hpp src/config/node.hpp)
add_executable(build_graph ${SOURCE_FILES})
target_link_libraries(build_graph ${CONAN_LIBS})