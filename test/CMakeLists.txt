cmake_minimum_required(VERSION 3.3)
include_directories(${INCLUDE_DIR})
add_executable(queueTest main.c)
target_link_libraries(queueTest ${BUILD_DIR}/lib/libqueue.a)
