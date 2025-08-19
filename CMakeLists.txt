cmake_minimum_required(VERSION 3.15)

project(sensor_fusion_simulator
VERSION 0.1.0
LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

add_executable(sensor_fusion_simulator)

target_sources(sensor_fusion_simulator PRIVATE
src/main.cpp
src/fusion_engine.cpp
src/sensor_manager.cpp
src/sensor.cpp
src/temperature_sensor.cpp
)

target_include_directories( sensor_fusion_simulator PRIVATE
  ${PROJECT_SOURCE_DIR}/include
)

if(MSVC)
  target_compile_options(sensor_fusion_simulator PRIVATE /W4 /permissive-)
else()
  target_compile_options(sensor_fusion_simulator PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_compile_definitions(sensor_fusion_simulator PRIVATE SOME_FLAG=1)

set_property(TARGET sensor_fusion_simulator PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)