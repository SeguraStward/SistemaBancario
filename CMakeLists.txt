cmake_minimum_required(VERSION 3.16)
project(SistemaBancario CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB FUENTES ${CMAKE_SOURCE_DIR}/*.cpp)
add_executable(sistema_bancario ${FUENTES})
