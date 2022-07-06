cmake_minimum_required(VERSION 3.4.1)
project(liangzi)

set(CMAKE_CXX_STANDARD 17)                      # c++14
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告

#Bring the headers, such as Student.h into the project
include_directories(include
    # zlib/include
)

# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES
    "src/*.cpp"
)

add_executable(last ${SOURCES})

target_link_libraries(last
    z
)



