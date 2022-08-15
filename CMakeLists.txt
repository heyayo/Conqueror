cmake_minimum_required(VERSION 3.23)
project(Prototype)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

add_executable(Prototype
        main.cpp
        func.cpp
        Entity.cpp
        Maths.cpp)

target_include_directories(Prototype PUBLIC headers)
target_link_libraries(Prototype ${CMAKE_SOURCE_DIR}/lib/libraylib.a)
