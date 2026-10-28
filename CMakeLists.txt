cmake_minimum_required(VERSION 3.17) #версия CMake которая нужна бля сборки

project(Trip_planner VERSION 1.0) #название проекта (после будет именем исполняемого файла) и версия

set(CMAKE_CXX_STANDARD 17) #устанавливаем версию стандарта С++

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(INCLUDE_DIR_QT ${CMAKE_SOURCE_DIR}/include/qt)
set(SRC_DIR_QT ${CMAKE_SOURCE_DIR}/src/qt)
set(INCLUDE_DIR_CORE ${CMAKE_SOURCE_DIR}/include/core)
set(SRC_DIR_CORE ${CMAKE_SOURCE_DIR}/src/core)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_AUTOMOC ON) #для сигналов и слотов        
set(CMAKE_AUTOUIC ON) #для дизайна окон
set(CMAKE_AUTORCC ON) #для ресурсов

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG f091b2c061b307ee89b164c39976fc9202a1c79d) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

#set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake") #путь к пакетным файлам Qt
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED) #поиск и установка из пакетных файлов


add_subdirectory(src)
add_subdirectory(nlohmann_json)


