cmake_minimum_required(VERSION 3.8.0)

# Set compiler to clang
set(CMAKE_CXX_COMPILER clang++)

project(bank-cli-2 CXX)
set(TARGET bank-cli-2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD   99)

set(CMAKE_CXX_COMPILER_FLAGS "-std=c++17 -O2 -g -Wall -Wextra -Werror -Wpedantic -Wshadow")

# Yoink protobuf
include(FetchContent)
FetchContent_Declare(
	protobuf
	URL https://github.com/protocolbuffers/protobuf/releases/download/v3.19.1/protobuf-cpp-3.19.1.zip
)
FetchContent_MakeAvailable(protobuf)

# Include directories
include_directories(${TARGET} include build/_deps/protobuf-src/src)
set(INCLUDE_DIR include)

# Source directories
set(SOURCE_DIR src)

# Add sources
set(SOURCES
    # CXX sources
    ${SOURCE_DIR}/Account.cpp
    ${SOURCE_DIR}/Authentication.cpp
    ${SOURCE_DIR}/Client.cpp
    ${SOURCE_DIR}/Customer.cpp
    ${SOURCE_DIR}/DataBase.cpp
    ${SOURCE_DIR}/Logger.cpp
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
    ${INCLUDE_DIR}/Logger.hpp
    ${INCLUDE_DIR}/Transaction.hpp
    ${INCLUDE_DIR}/Utils.hpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#enable_testing()
add_executable(${TARGET} ${SOURCES})
#target_link_libraries(
	#accounts_test
	#gtest_main
#)
