cmake_minimum_required(VERSION 3.17)
project(beta_bank C)

set(CMAKE_C_STANDARD 99)

add_executable(beta_bank main.c notlar.h frontend.h backend.h cmake-build-debug/user1.txt cmake-build-debug/user2.txt cmake-build-debug/user3.txt)
