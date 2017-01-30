cmake_minimum_required (VERSION 2.8)

project(online-platform)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -fpermissive)
set(EXECUTABLE_OUTPUT_PATH ../toys)

aux_source_directory(./src DIR_SRCS)
add_executable(echo-server toys/echo-server.cpp ${DIR_SRCS})
#add_executable(test test/main.cpp ${DIR_SRCS})

target_link_libraries(echo-server glog)
target_link_libraries(echo-server pthread)
