cmake_minimum_required(VERSION 3.27)
project(Programing_Project C)

set(CMAKE_C_STANDARD 23)

add_executable(Programing_Project main.c
        "Headers/structures_operations.h"
        "Headers/file_manip.h"
        Headers/UI.h
        Sources/UI.c
        "Sources/file_manip.c"
        "Sources/structures_operations.c"
        "Headers/struct.h"
        "Headers/generate.h"
        "Sources/generate.c"
        "Sources/fetching.c"
        "Headers/fetching.h"
        "Sources/string_operations.c"
        "Headers/string_operations.h"
        "Sources/user_input.c"
        "Headers/user_input.h"
        "Sources/main_functions.c"
        "Headers/main_functions.h"
        Sources/validators.c
        Headers/validators.h
)
