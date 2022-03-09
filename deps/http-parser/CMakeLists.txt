cmake_minimum_required(VERSION 3.4)
project(http-parser LANGUAGES C)


include_directories(${CMAKE_SOURCE_DIR})
set(http_sources
    http_parser.c)


add_library(http_parser SHARED ${http_sources})

add_library(http_parser_a STATIC ${http_sources})
