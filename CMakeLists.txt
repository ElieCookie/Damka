cmake_minimum_required(VERSION 3.20)
project(Damka_Project C)

set(CMAKE_C_STANDARD 99)

add_executable(Damka_Project game.c general.c general_settings.c q1.c q3.c q2.c)
