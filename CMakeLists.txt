cmake_minimum_required(VERSION 3.27)
project(Programing_Project C)

set(CMAKE_C_STANDARD 23)

add_executable(Programing_Project main.c
        "Structure Operations/structures.h"
        "DataBase Operations/file_manip.h"
        UI/UI.h
        UI/UI.c
        "DataBase Operations/file_manip.c"
        "Structure Operations/strucutres.c"
        "Structure Operations/struct.h"
)
