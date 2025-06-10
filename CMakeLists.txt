cmake_minimum_required(VERSION 3.30)
project(chatbotcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(chatbotcpp main.cpp
        ChatBot.cpp
        ChatBot.h)
