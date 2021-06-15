cmake_minimum_required(VERSION 3.19)
project(MeganExcelProcessor)

set(CMAKE_CXX_STANDARD 20)


add_executable(MeganExcelProcessor main.cpp struct/util.cpp struct/util.h struct/DayEntry.cpp struct/DayEntry.h)
