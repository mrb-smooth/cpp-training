cmake_minimum_required(VERSION 3.8.0)

## Set compiler to clang
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_FLAGS "-std=c++17 -O2 -g -Wall -Wextra -Werror -Wpedantic -Wshadow")

## Initialize project
project(bank-cli-2 CXX)
set(TARGET bank-cli-2)
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
    ${SOURCE_DIR}/Account.cpp
    ${SOURCE_DIR}/Authentication.cpp
    ${SOURCE_DIR}/Client.cpp
    ${SOURCE_DIR}/Customer.cpp
    ${SOURCE_DIR}/DataBase.cpp
    ${SOURCE_DIR}/Logging.cpp
    ${SOURCE_DIR}/Main.cpp
    ${SOURCE_DIR}/Transaction.cpp
    #${SOURCE_DIR}/protoballs.cpp       # GOOGLE EXAMPLE
    # CXX includes
    ${INCLUDE_DIR}/Account.hpp
    #${INCLUDE_DIR}/Addressbook.pb.hpp  # GOOGLE EXAMPLE
    ${INCLUDE_DIR}/Authentication.hpp
    ${INCLUDE_DIR}/Client.hpp
    ${INCLUDE_DIR}/Customer.hpp
    ${INCLUDE_DIR}/DataBase.hpp
    ${INCLUDE_DIR}/Definitions.hpp
    ${INCLUDE_DIR}/Encryption.hpp
    ${INCLUDE_DIR}/Logging.hpp
    ${INCLUDE_DIR}/Transaction.hpp
    ${INCLUDE_DIR}/Utils.hpp
)

## Protobuf Config
set(Protubuf_INCLUDE_DIR ${SOURCE_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${SOURCE_DIR}/Account.proto)
#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS EXPORT_MACRO DLL_EXPORT Account.proto)
#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS DESCRIPTORS PROTO_DESCS Account.proto)

## Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#enable_testing()

## Executable and link dependencies
add_executable(${TARGET} ${SOURCES} ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(${TARGET} ${Protobuf_LIBRARIES})
