cmake_minimum_required( VERSION 3.1.0 )
project( goslam )


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -march=native")

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
if(COMPILER_SUPPORTS_CXX17)
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
     add_definitions(-DCOMPILERWITHC17)
     message(STATUS " Using flag -std=c++17.")
endif()
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenCV REQUIRED)

message(STATUS ${OpenCV})

include_directories(
${PROJECT_SOURCE_DIR}
"/usr/include/eigen3"
)


add_executable(${PROJECT_NAME}
src/main.cc 
src/Frame.cc
src/ORB.cc
)

#add_executable(${PROJECT_NAME}
#test/border.cc
#)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME}
${OpenCV_LIBS}
${Eigen_LIBS}
)
