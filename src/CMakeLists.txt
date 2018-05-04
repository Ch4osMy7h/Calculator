cmake_minimum_required(VERSION 3.9)

project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Calculator main.cpp Stack.h Vector.h BinNode.cpp BinNode.h BinTree.cpp BinTree.h Expression.cpp Expression.h Complex.cpp Complex.h)