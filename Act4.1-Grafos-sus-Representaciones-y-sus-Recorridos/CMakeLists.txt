cmake_minimum_required(VERSION 3.20)
project(Act4_1_Grafos_sus_Representaciones_y_sus_Recorridos)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Act4_1_Grafos_sus_Representaciones_y_sus_Recorridos
        g.txt
        graph.h
        main.cpp
        star.txt)
