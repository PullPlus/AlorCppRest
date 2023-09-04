cmake_minimum_required(VERSION 3.1)

project(AlorCpp)

#add_executable(AlorCpp main.cpp)
include_directories(include/)
include_directories(AlorCppRest/include/)
#include_directories(generate/generated_project/src/)

file(GLOB_RECURSE HEADER_FILES "include/*.h")
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
#file(GLOB_RECURSE HEADER_FILES "AlorCppRest/include/*.h")
#file(GLOB_RECURSE SOURCE_FILES "AlorCppRest/src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${HEADER_FILES} ${SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(Threads REQUIRED)
find_package(cpprestsdk REQUIRED)
find_package(Boost REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/AlorCppRest/build/libAlorCppRest.a)
if (UNIX)
    message(STATUS "Building client library for Linux/Unix")

    target_link_libraries(${PROJECT_NAME} PUBLIC cpprest ${Boost_LIBRARIES} crypto)
else()
    message(STATUS "Building client library for Windows")

    target_link_libraries(${PROJECT_NAME} PUBLIC cpprestsdk::cpprest ${Boost_LIBRARIES} bcrypt)
endif()



install(TARGETS AlorCpp RUNTIME DESTINATION bin)
