cmake_minimum_required(VERSION 3.23)
project(ProjAED)

set(CMAKE_CXX_STANDARD 14)




add_executable(ProjAED main.cpp Student.cpp Student.h Lesson.cpp Lesson.h Class.cpp Class.h Uni.cpp Uni.h Readfiles.h UCclass.cpp UCclass.h Request.cpp Request.h Menu.cpp Menu.h)

target_link_libraries(ProjAED)