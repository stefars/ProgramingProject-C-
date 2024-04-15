cmake_minimum_required(VERSION 3.27)
project(Programing_Project C)

set(CMAKE_C_STANDARD 23)

add_executable(Programing_Project main.c
        "Headers/structures.h"
        "Headers/file_manip.h"
        Headers/UI.h
        Sources/UI.c
        "Sources/file_manip.c"
        "Sources/strucutres.c"
        "Headers/struct.h"
        "Headers/generate.h"
        "Sources/generate.c"
        "Sources/Fetching.c"
        "Headers/Fetching.h"
        "Sources/String Operations.c"
        "Headers/String Operations.h"
        "Sources/User Input.c"
        "Headers/User Input.h"
        "Sources/Main Functions.c"
        "Headers/Main Functions.h"
)
