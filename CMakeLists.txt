cmake_minimum_required(VERSION 3.20)
project(Damka_Project C)

set(CMAKE_C_STANDARD 11)

add_executable(Damka_Project general.h ex1/general_settings.h game.c general_functions.c)
