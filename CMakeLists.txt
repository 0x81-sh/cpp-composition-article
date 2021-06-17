cmake_minimum_required(VERSION 3.17)
project(article)

set(CMAKE_CXX_STANDARD 14)

add_executable(article main.cpp date/Date.cpp date/Date.h string/MyString.cpp string/MyString.h Article.cpp Article.h)
add_executable(date_test date/Date.cpp date/Date.h date/main.cpp)
add_executable(string_test string/MyString.cpp string/MyString.h string/main.cpp string/TEST2.h)
