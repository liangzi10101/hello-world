cmake_minimum_required(VERSION 3.4.1)
project(liangzi)

set(CMAKE_CXX_STANDARD 17)                      # c++14
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告
set(root .)
add_definitions(-DTIXML_USE_STL=1)

#Bring the headers, such as Student.h into the project
include_directories(include
    # zlib/include
    ${root}/3rd/tinyxml
)

# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES
    src/*.cpp

    # 3rd
    ${root}/3rd/tinyxml/tinystr.cpp
    ${root}/3rd/tinyxml/tinyxml.cpp
    ${root}/3rd/tinyxml/tinyxmlparser.cpp
    ${root}/3rd/tinyxml/tinyxmlerror.cpp
)

add_executable(last ${SOURCES})

target_link_libraries(last
    z
)



