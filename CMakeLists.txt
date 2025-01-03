cmake_minimum_required(VERSION 3.15...3.27)
project(PYHPX CXX)

find_package(HPX REQUIRED)

if(CMAKE_VERSION VERSION_LESS 3.18)
    set(DEV_MODULE Development)
else()
    set(DEV_MODULE Development.Module)
endif()

find_package(Python 3.13 COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)
execute_process(
    COMMAND python3 -m nanobind --cmake_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE nanobind_ROOT)
find_package(nanobind CONFIG REQUIRED)

nanobind_add_module(pyhpx src/main.cpp)
target_include_directories(pyhpx PRIVATE include)
target_link_libraries(pyhpx PRIVATE HPX::hpx HPX::wrap_main HPX::iostreams_component)