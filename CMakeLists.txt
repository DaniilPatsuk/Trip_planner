cmake_minimum_required(VERSION 3.17) #версия CMake которая нужна бля сборки

project(Trip_planner VERSION 1.0) #название проекта (после будет именем исполняемого файла) и версия

set(CMAKE_CXX_STANDARD 14) #устанавливаем версию стандарта С++
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_AUTOMOC ON) #для сигналов и слотов        
set(CMAKE_AUTOUIC ON) #для дизайна окон
set(CMAKE_AUTORCC ON) #для ресурсов

#set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake") #путь к пакетным файлам Qt
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED) #поиск и установка из пакетных файлов


add_subdirectory(src)


