cmake_minimum_required (VERSION 2.6)

SET(EXECUTABLE_OUTPUT_PATH "Release")
SET(EXECUTABLE_NAME "suntzu")

project (${EXECUTABLE_NAME})

SET(CMAKE_MODULE_PATH ".")
SET( CMAKE_CXX_FLAGS  " -std=c++11 ${CMAKE_CXX_FLAGS} " )	

find_package(Boost REQUIRED COMPONENTS system thread atomic chrono)
include_directories(${Boost_INCLUDE_DIRS})

find_package(TCLAP REQUIRED)
include_directories(${TCLAP_INCLUDE_PATH})

include_directories(${CMAKE_SOURCE_DIR}/Source)

SET(SRC "")
SET(CCSD ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Source)

add_executable(${EXECUTABLE_NAME} ${SRC})
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})

# strict
add_definitions( -Werror )
######

# fast compile
add_definitions( "-O0 " )
######

# debug
add_definitions( " -O0 -g3 -DDEBUG " )
######
