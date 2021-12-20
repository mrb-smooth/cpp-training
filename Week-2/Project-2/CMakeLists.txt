cmake_minimum_required(VERSION 3.8.0)

## Set compiler to clang
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_FLAGS "-std=c++17 -O2 -g -Wall -Wextra -Werror -Wpedantic -Wshadow")

## Initialize project
project(bank-cli-2 CXX)
set(TARGET bank-cli-2)
set(TESTS run-tests)

# Dependencies
find_package(Protobuf REQUIRED)

## Set standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD   99)

## Include directories
include_directories(${TARGET} ${Protobuf_INCLUDE_DIRS})
include_directories(${TARGET} ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${TARGET} Includes)
set(INCLUDE_DIR Includes)

## Source directories
set(SOURCE_DIR Sources)

## Add CXX sources
set(SOURCES
    # CXX sources
    ${SOURCE_DIR}/Authentication.cpp
    ${SOURCE_DIR}/Client.cpp
    ${SOURCE_DIR}/DataBase.cpp
    ${SOURCE_DIR}/Logging.cpp
    ${SOURCE_DIR}/Main.cpp
    # CXX includes
    ${INCLUDE_DIR}/Authentication.hpp
    ${INCLUDE_DIR}/Client.hpp
    ${INCLUDE_DIR}/DataBase.hpp
    ${INCLUDE_DIR}/Logging.hpp
)

## Protobuf Config
set(Protubuf_INCLUDE_DIR ${SOURCE_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${SOURCE_DIR}/Account.proto)

## Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

## Application executable and link dependencies
add_executable(${TARGET} ${SOURCES} ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(${TARGET} ${Protobuf_LIBRARIES})

## Include directories
include_directories(${TARGET} ${Protobuf_INCLUDE_DIRS})
include_directories(${TARGET} ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${TARGET} Includes Tests)
set(INCLUDE_DIR Includes)
set(TESTS_DIR Tests)

## Source directories
set(SOURCE_DIR Sources)

## Add CXX sources
set(TEST_SOURCES
    # CXX sources
    ${SOURCE_DIR}/Authentication.cpp
    ${SOURCE_DIR}/Client.cpp
    ${SOURCE_DIR}/DataBase.cpp
    ${SOURCE_DIR}/Logging.cpp
    ${TESTS_DIR}/AuthenticationTest.cpp
    ${TESTS_DIR}/DataBaseTest.cpp
    ${TESTS_DIR}/TestSuite.cpp
    # CXX includes
    ${INCLUDE_DIR}/Authentication.hpp
    ${INCLUDE_DIR}/Client.hpp
    ${INCLUDE_DIR}/DataBase.hpp
    ${INCLUDE_DIR}/Logging.hpp
    ${TESTS_DIR}/AuthenticationTest.hpp
    ${TESTS_DIR}/DataBaseTest.hpp
    ${TESTS_DIR}/TestSuite.hpp
)

## Test executable and link dependencies
add_executable(${TESTS} ${TEST_SOURCES} ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(${TESTS} ${Protobuf_LIBRARIES})
