cmake_minimum_required(VERSION 3.5)
project(chinese)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

message(STATUS ${OpenCV_LIBRARY_DIRS})

include_directories(
        /usr/include/freetype2/
        ${OpenCV_INCLUDE_DIRS}
        )

#link_directories(${OpenCV_LIBRARY_DIRS} )

add_executable(chinese main.cpp CvxText.cpp CvxText.h)

target_link_libraries(chinese ${OpenCV_LIBS} freetype)