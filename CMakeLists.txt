cmake_minimum_required(VERSION 3.17)
project(semaphores)


set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        sem.h
        syn.h
        buf.h)
set(PROJECT_SOURCES
        buf.cpp
        sem.cpp
        syn.cpp
        main.cpp)

add_executable(semaphores ${PROJECT_HEADERS} ${PROJECT_SOURCES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(semaphores PRIVATE Threads::Threads)
