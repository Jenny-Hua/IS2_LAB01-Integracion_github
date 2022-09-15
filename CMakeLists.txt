cmake_minimum_required(VERSION 3.23)
project(LAB13_Seam_carving)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)

# Incluir libreria OPENCV4
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_executable(main
#        main_2.cpp
        main.cpp
        )

target_link_libraries(main ${OpenCV_LIBS})
