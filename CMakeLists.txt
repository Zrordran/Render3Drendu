cmake_minimum_required(VERSION 3.8)
project(Render3Db)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp tgaimage.cpp tgaimage.h model.cpp model.h Point.cpp Point.h Vector.cpp Vector.h Matrix.cpp Matrix.h)
add_executable(Render3Db ${SOURCE_FILES})