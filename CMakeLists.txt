cmake_minimum_required(VERSION 3.3.2)
project(adaboost CXX)

# First, define all the compilation options.
option(BUILD_TESTS "Build tests." ON)
option(INSTALL_TESTS "Install tests." OFF)

# Set required standard to C++11.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recurse into the rest of the project.
include_directories(adaboost)
add_subdirectory(adaboost)
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(NOT INSTALL_TESTS)
    install(DIRECTORY adaboost DESTINATION /usr/local/include
            PATTERN "CMakeLists.txt" EXCLUDE
            )
endif()
