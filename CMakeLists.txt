cmake_minimum_required(VERSION 3.15)

project(MyProject LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE="${CMAKE_BINARY_DIR}/build/conan_toolchain.cmake")
if(NOT CMAKE_BUILD_TYPE)
    set(DCMAKE_BUILD_TYPE RelWithDebInfo)
endif()

find_program(CONAN_EXECUTABLE conan)
if (NOT CONAN_EXECUTABLE)
    message(FATAL_ERROR "Conan is not installed. Please install Conan to continue.")
endif()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the build type" FORCE)
endif()


message(STATUS "Running 'conan install' to fetch dependencies...")

execute_process(
    COMMAND ${CONAN_EXECUTABLE} install ${CMAKE_SOURCE_DIR} --output-folder=${CMAKE_BINARY_DIR} --build=missing -s build_type=${CMAKE_BUILD_TYPE}
    RESULT_VARIABLE conan_result
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

if (conan_result)
    message(FATAL_ERROR "Conan install failed with error code ${conan_result}")
endif()

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(GTest REQUIRED CONFIG)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(cariad_library ${SOURCES} ${HEADERS})

add_executable(cariad_exec "src/main.cpp")

target_link_libraries(cariad_exec PRIVATE cariad_library)

add_executable(my_tests tests/test_cariad.cpp)

target_link_libraries(my_tests PRIVATE GTest::gtest GTest::gtest_main cariad_library)

enable_testing()
add_test(NAME my_test COMMAND my_tests)