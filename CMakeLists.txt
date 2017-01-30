cmake_minimum_required (VERSION 2.8)

project(online-platform)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -fpermissive)

#
#   添加源代码目录
#
aux_source_directory(./src DIR_SRCS)

add_executable(echo-client echo-client.cpp ${DIR_SRCS})
#add_executable(test test/main.cpp ${DIR_SRCS})

target_link_libraries(echo-client glog)
target_link_libraries(echo-client pthread)
