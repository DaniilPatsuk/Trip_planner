cmake_minimum_required(VERSION 3.17)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../ui") #установили значение для переменной, которую CMake будет использовтаь при поиске файлов интерфейсов

add_executable(app main.cpp choose_date.cpp city.cpp event.cpp mainwindow.cpp scroll_widget.cpp
                ${MY_INCLUDE_DIR}/choose_date.h
                ${MY_INCLUDE_DIR}/city.h
                ${MY_INCLUDE_DIR}/event.h
                ${MY_INCLUDE_DIR}/mainwindow.h
                ${MY_INCLUDE_DIR}/scroll_widget.h)



target_include_directories(app PRIVATE ${MY_INCLUDE_DIR})

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../ui") #установили значение для переменной, которую CMake будет использовтаь при поиске файлов интерфейсов

target_link_libraries(app PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets) #линкует найденные библиотеки Qt к программе