cmake_minimum_required (VERSION 2.6)
project (suntzu)

SET(CMAKE_MODULE_PATH ".")

SET(EXECUTABLE_OUTPUT_PATH "Release")

add_executable(suntzu

	Source/Main.cc

)

find_package(Boost REQUIRED COMPONENTS system thread atomic chrono)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(suntzu ${Boost_LIBRARIES})

SET( CMAKE_CXX_FLAGS  " -std=c++11 ${CMAKE_CXX_FLAGS} " )	
