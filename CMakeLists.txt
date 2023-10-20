cmake_minimum_required(VERSION 3.20)

project(interviewProject LANGUAGES CXX)


add_library(curves SHARED
    curves/sources/curves.cpp
)
target_include_directories(curves PRIVATE "${PROJECT_SOURCE_DIR}/curves/include")
set_target_properties(curves PROPERTIES PUBLIC_HEADER curves/include/curves.h)

add_executable(main
    main.cpp
)

target_include_directories(main PRIVATE "${PROJECT_SOURCE_DIR}/curves/include")
target_link_libraries(main PRIVATE curves)

target_compile_features(main PRIVATE cxx_std_17)
