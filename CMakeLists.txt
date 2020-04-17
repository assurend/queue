cmake_minimum_required(VERSION 3.3)
project(queue)
set(CMAKE_BUILD_TYPE Release)

SET ( PROJ_DIR         "queue" )
SET ( PROJ_TEST_DIR    "test_queue" )
SET ( BUILD_DIR   "${PROJECT_SOURCE_DIR}/build" )
SET ( INCLUDE_DIR     "${PROJECT_SOURCE_DIR}/include" )
SET ( SOURCE_DIR  "${PROJECT_SOURCE_DIR}/src" )
SET ( TEST_DIR    "${PROJECT_SOURCE_DIR}/test" )

include_directories(include)

set(SOURCES
    src/queue.c
)

add_library(queue STATIC ${SOURCES})
install(TARGETS queue DESTINATION ${PROJECT_SOURCE_DIR}/build/lib/)
