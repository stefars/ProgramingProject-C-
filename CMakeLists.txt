cmake_minimum_required(VERSION 3.27)
project(Programing_Project C)

set(CMAKE_C_STANDARD 23)

add_executable(Programing_Project main.c
        structures.h
        file_manip.h
        UI.h
)
