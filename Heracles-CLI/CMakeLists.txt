cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

add_executable(Heracles-CLI
        src/CLI.cpp)

target_link_libraries(Heracles-CLI LINK_PRIVATE Heracles)