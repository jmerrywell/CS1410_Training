cmake_minimum_required(VERSION 3.28)
project(cpp_starter_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Project structure:
#   - Header files (.h)  → include/
#   - Source files (.cpp) → src/
#
# Add one line per program. For programs with multiple .cpp files,
# list them all space-separated after the program name.
# After any change to this file, re-run: cmake .. (from the build/ folder)
#
# Examples:
#   add_executable(main src/main.cpp)
#   add_executable(a1 src/assignmeht1.cpp)
#   add_executable(lab2 src/lab2.cpp src/helpers.cpp)
add_executable(main src/main.cpp)
add_executable(lab0201 src/CodinglabCS1410-0201.cpp)
add_executable(lab0202 src/CodinglabCS1410-0202.cpp)
add_executable(lab0203 src/CodinglabCS1410-0203.cpp)
add_executable(lab0301 src/CodinglabCS1410-0301.cpp)
add_executable(lab0302 src/CodinglabCS1410-0302.cpp)
add_executable(lab1111 src/CodinglabCS1410-Shape_Collection.cpp)
add_executable(lab0401 src/CodinglabCS1410-0401.cpp)
add_executable(lab0402 src/CodinglabCS1410-0402.cpp)
add_executable(lab0501 src/CodinglabCS1410-0501.cpp)
add_executable(lab0502 src/CodinglabCS1410-0502.cpp)
add_executable(a2 src/a2.cpp)
add_executable(lab0601 src/CodinglabCS1410-0601.cpp)
add_executable(lab0602 src/CodinglabCS1410-0602.cpp)
add_executable(lab0603 src/CodinglabCS1410-0603.cpp)
