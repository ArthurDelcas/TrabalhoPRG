cmake_minimum_required(VERSION 3.20)
project(ArvoreBuscaBinaria C)

set(CMAKE_C_STANDARD 99)

include_directories(src)

add_executable(TrabalhoPRG src/main.c src/arvore_busca_binaria.c)