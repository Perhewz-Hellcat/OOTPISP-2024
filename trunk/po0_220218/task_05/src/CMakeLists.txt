cmake_minimum_required(VERSION 3.15.0)

project(LAB_05_220218)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES main.cpp CTime.cpp)

set(HEADER_FILES CTime.h Vector.h QVector.h)

set(ALL_SOURCES ${HEADER_FILSE}
				${SOURCE_FILES})

add_executable(${PROJECT_NAME} ${ALL_SOURCES})