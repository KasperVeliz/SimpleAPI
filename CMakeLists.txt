cmake_minimum_required(VERSION 4.2)
set (CMAKE_CXX_STANDARD 17)
project(simpleapi)
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PkgConfig::Pistache)


