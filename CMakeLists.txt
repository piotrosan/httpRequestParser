cmake_minimum_required(VERSION 3.31)
project(httpRequestParser)

set(CMAKE_CXX_STANDARD 20)

add_executable(httpRequestParser main.cpp
        parser/parser.h
        parser/request.h)
