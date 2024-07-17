cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

# Depedencies
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-4.0)

# Add Sources
add_executable(Cauldron src/Cauldron.cpp
        src/App.cpp
        src/Cauldron.h)

# Link libraries
target_include_directories(Cauldron PRIVATE ${GTKMM_INCLUDE_DIRS})

target_link_directories(Cauldron PRIVATE ${GTKMM_LIBRARY_DIRS})

target_link_libraries(Cauldron ${GTKMM_LIBRARIES} Heracles)
