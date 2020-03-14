cmake_minimum_required(VERSION 3.15)
project(cpp_minidb)

set(CMAKE_CXX_STANDARD 11)
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")
file(GLOB TABLE_HEADERS "table/*.cpp")
file(GLOB TABLE_SOURCES "table/*.h")
file(GLOB FILE_HEADERS "file/*.cpp")
file(GLOB FILE_SOURCES "file/*.h")
file(GLOB CORE_HEADERS "core/*.cpp")
file(GLOB CORE_SOURCES "core/*.h")
file(GLOB LEXICAL_HEADERS "lexical/*.cpp")
file(GLOB LEXICAL_SOURCES "lexical/*.h")

add_executable(cpp_minidb
        ${HEADERS} ${SOURCES}
        ${TABLE_HEADERS} ${TABLE_SOURCES}
        ${FILE_HEADERS} ${FILE_SOURCES}
        ${CORE_HEADERS} ${CORE_SOURCES}
        ${LEXICAL_HEADERS} ${LEXICAL_SOURCES}
        )