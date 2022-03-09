cmake_minimum_required(VERSION 3.4)
project(libuv-easyhttp)



add_definitions(-std=c++11)

link_directories( ${CMAKE_SOURCE_DIR}/build/deps/libuv-v1.43.0  
${CMAKE_SOURCE_DIR}/build/deps/http-parser 
${CMAKE_SOURCE_DIR}/build/deps/spdlog-1.x
) # 指定库搜索路径

add_subdirectory(deps/libuv-v1.43.0)
add_subdirectory(deps/http-parser)
add_subdirectory(deps/spdlog-1.x)

# 头文件
include_directories(${CMAKE_SOURCE_DIR}/include 
${CMAKE_SOURCE_DIR}/deps/libuv-v1.43.0/include 
${CMAKE_SOURCE_DIR}/deps/http-parser  
${CMAKE_SOURCE_DIR}/deps/spdlog-1.x/include
)
# 源码
FILE (GLOB EASY_HTTP_SRCS "*.cpp" "*.c" "./src/*.cpp" )
# set(EASY_HTTP_SRCS main.cpp src/HttpServer.cpp)

# AUX_SOURCE_DIRECTORY(. SRC_LIST)

ADD_EXECUTABLE(main ${EASY_HTTP_SRCS})

target_link_libraries(main http_parser_a uv_a spdlog) # 链接外部库