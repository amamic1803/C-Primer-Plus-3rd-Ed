cmake_minimum_required(VERSION 3.29)

project(C_Primer_Plus C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

find_program(CLANG_TIDY_EXE NAMES clang-tidy REQUIRED)
set(CMAKE_C_CLANG_TIDY "${CLANG_TIDY_EXE};--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy")

add_compile_definitions(_CRT_SECURE_NO_WARNINGS)


# executable
file(GLOB_RECURSE EXERCISE_SOURCES
        exercises/*.c
        exercises/*.h
)
add_executable(
        C_Primer_Plus
        main.c
        exercises.h
        ${EXERCISE_SOURCES}
)
target_link_libraries(C_Primer_Plus
        $<$<PLATFORM_ID:Linux>:m>
)
set_target_properties(C_Primer_Plus PROPERTIES
        LANGUAGE C
        LINKER_LANGUAGE C
        OUTPUT_NAME C_Primer_Plus
)
target_compile_options(C_Primer_Plus PRIVATE
        $<$<C_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic -Werror>
)
