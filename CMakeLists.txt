cmake_minimum_required(VERSION 3.5.1)
project(cpp_euler)
file(GLOB CPP_EULER_SOURCES "src/*.cpp")
add_executable(cpp_euler ${CPP_EULER_SOURCES})
