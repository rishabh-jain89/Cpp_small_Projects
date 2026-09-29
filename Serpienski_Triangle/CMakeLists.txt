cmake_minimum_required(VERSION 3.24)
project(sierpinski CXX)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
)
FetchContent_MakeAvailable(SFML)

add_executable(sierpinski main.cpp)

target_link_libraries(sierpinski PRIVATE sfml-graphics)