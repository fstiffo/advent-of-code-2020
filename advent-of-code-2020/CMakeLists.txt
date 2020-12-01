# CMakeList.txt : CMake project for advent-of-code-2020, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (advent-of-code-2020 "advent-of-code-2020.cpp" "advent-of-code-2020.h" "d01.cpp" "utils.h" "utils.cpp")

# TODO: Add tests and install targets if needed.
find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(advent-of-code-2020 PRIVATE unofficial::sqlite3::sqlite3)