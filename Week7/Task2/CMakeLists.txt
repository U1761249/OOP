cmake_minimum_required(VERSION 3.12)
project(Task2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task2 .cppFiles/main.cpp .cppFiles/Account.cpp .hFiles/Account.h CurrentAccount.cpp CurrentAccount.h)