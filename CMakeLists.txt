cmake_minimum_required(VERSION 3.20)
project(ArvoreBuscaBinaria C)

# Define o padrão C99 para garantir compatibilidade
set(CMAKE_C_STANDARD 99)

# Informa ao compilador onde encontrar os arquivos de cabeçalho
include_directories(src)

# Cria o executável a partir dos arquivos fonte
add_executable(projeto_bst src/main.c src/bst.c)