cmake_minimum_required(VERSION 3.29.5)
project(sqlite3Practice)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

# add sqlite3Practice source files
set(MAIN_SOURCES
main.cpp
)

# add sqlite3 source files
set(SQLITE3_DIR ${CMAKE_SOURCE_DIR}/lib/sqlite3)
set(SQLITE3_SOURCES
  ${SQLITE3_DIR}/sqlite3.c
)

include_directories(${SQLITE3_DIR})

add_executable(
  ${PROJECT_NAME}
  ${MAIN_SOURCES}
  ${SQLITE3_SOURCES}
)
