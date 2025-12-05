cmake_minimum_required(VERSION 3.10)

# Only set vcpkg toolchain on Windows
if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
endif()

project(RobotSim)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)

add_executable(robot_sim main.cpp)

target_link_libraries(robot_sim
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

# Make SDL2 includes consistent across platforms
target_include_directories(robot_sim PRIVATE ${SDL2_INCLUDE_DIRS})