cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)
project(src/BitArray)
set(exe_name ${PROJECT_NAME})
set(test_name Tests)


if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_library(corelib OBJECT src/BitArray/BitArray.cpp)
add_executable(${exe_name} src/main.cpp)
target_link_libraries(${exe_name} corelib)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
    set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)
endif()

# скачиваем библиотеку GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# описываем исполняемый файл программы для запуска тестов: это cpp-файлы тестов + основная библиотека + библиотека gtest_main
# наш собственный main.cpp здесь не нужен, т.к. функция main реализована в gtest_main
add_executable(${test_name} test/Tests.cpp)
target_link_libraries(${test_name} gtest_main)
target_link_libraries(${test_name} corelib)
