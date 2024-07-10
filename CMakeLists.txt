# CMake
cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

if(NOT ${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR}/build)
    message(FATAL_ERROR "Unsupported directory, CMake will exit.")
endif()

# Project
project(game LANGUAGES CXX)

# Host
if(NOT ${CMAKE_SYSTEM_NAME} MATCHES Linux|Windows)
    message(FATAL_ERROR "Unsupported host, CMake will exit.")
endif()

# Compiler
if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    set(CMAKE_CXX_COMPILER g++)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
endif()

if(NOT ${CMAKE_CXX_COMPILER_ID} MATCHES GNU)
    message(FATAL_ERROR "Unsupported compiler, CMake will exit.")
endif()

if(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 13.1)
    message(FATAL_ERROR "Outdated compiler, CMake will exit.")
endif()

# Headers
include_directories(${CMAKE_SOURCE_DIR}/include/)

# Sources
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*)
add_executable(${PROJECT_NAME} ${SOURCES})

# Libraries
if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libwizard_engine.so)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/bin/libwizard_engine.dll)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    file(GLOB LIBRARIES ${CMAKE_SOURCE_DIR}/lib/*)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
    file(GLOB LIBRARIES ${CMAKE_SOURCE_DIR}/bin/*)
endif()

file(COPY ${LIBRARIES} DESTINATION ${CMAKE_BINARY_DIR})

# Flags
file(READ ${CMAKE_SOURCE_DIR}/compile_flags.txt FLAGS)
string(REPLACE \n \  FLAGS ${FLAGS})

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    set(CMAKE_CXX_FLAGS "${FLAGS} -Wl,-rpath=./")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
    set(CMAKE_CXX_FLAGS "${FLAGS} -mwindows")
endif()

# Assets
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

# Test
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running test ${PROJECT_NAME}"
)
