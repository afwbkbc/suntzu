cmake_minimum_required (VERSION 2.6)
project (suntzu)

SET(CMAKE_MODULE_PATH ".")

SET(EXECUTABLE_OUTPUT_PATH "Release")

add_executable(suntzu

	Source/Utils/ArgumentParser.cc

	Source/UI/UI.cc
		Source/UI/Console/Console.cc
		
	Source/Core/SunTzu.cc

	Source/Main.cc
)

find_package(Boost REQUIRED COMPONENTS system thread atomic chrono)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(suntzu ${Boost_LIBRARIES})

find_package(TCLAP REQUIRED)
include_directories(${TCLAP_INCLUDE_PATH})

SET( CMAKE_CXX_FLAGS  " -std=c++11 ${CMAKE_CXX_FLAGS} " )	

include_directories(${CMAKE_SOURCE_DIR}/Source)

# strict
add_definitions( -Werror )
######

# fast compile
add_definitions( "-O0 " )
######

# debug
add_definitions( " -O0 -g3 -DDEBUG " )
######
