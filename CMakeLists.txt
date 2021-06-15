cmake_minimum_required(VERSION 3.19)
project(MeganExcelProcessor)

set(CMAKE_CXX_STANDARD 20)


add_executable(MeganExcelProcessor src/main.cpp src/struct/util.cpp src/struct/util.h src/struct/DayEntry.cpp src/struct/DayEntry.h)
