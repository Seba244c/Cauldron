cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

# Required packages
find_package(Boost 1.85 REQUIRED)

add_library(Heracles
        src/DnD/DnD.h
        src/Heracles/Content.cpp
        src/Heracles/Content.h
        src/Heracles.h
        src/hrpch.h
        src/hrpch.cpp
        src/Heracles/Utils/Serializer.cpp
        src/Heracles/Utils/Serializer.h
        src/DnD/DnD.cpp
)

target_include_directories(Heracles PUBLIC src ${Boost_INCLUDE_DIR})
target_precompile_headers(Heracles PRIVATE src/hrpch.h)

# Depedencies
target_link_libraries(Heracles PRIVATE ${Boost_LIBRARIES})
