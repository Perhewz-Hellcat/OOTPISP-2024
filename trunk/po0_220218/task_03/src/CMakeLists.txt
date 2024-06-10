cmake_minimum_required(VERSION 3.15.0)

project(LAB_03_220218)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES main.cpp NotEnoughMemory.cpp Store.cpp IError.cpp IOError.cpp ReadFileError.cpp WriteFileError.cpp)

set(HEADER_FILES NotEnoughMemory.h Store.h IError.h IOError.h ReadFileError.h WriteFileError.h) 

set(ALL_SOURCES ${HEADER_FILSE}
				${SOURCE_FILES})

add_executable(${PROJECT_NAME} ${ALL_SOURCES})