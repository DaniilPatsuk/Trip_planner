cmake_minimum_required(VERSION 3.17)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../ui") #установили значение для переменной, которую CMake будет использовтаь при поиске файлов интерфейсов

add_executable(Tul ${SRC_DIR_QT}/main.cpp 
                ${SRC_DIR_QT}/choose_date.cpp 
                ${SRC_DIR_QT}/city.cpp 
                ${SRC_DIR_QT}/event.cpp 
                ${SRC_DIR_QT}/mainwindow.cpp 
                ${SRC_DIR_QT}/scroll_widget.cpp
                ${INCLUDE_DIR_QT}/choose_date.h
                ${INCLUDE_DIR_QT}/city.h
                ${INCLUDE_DIR_QT}/event.h
                ${INCLUDE_DIR_QT}/mainwindow.h
                ${INCLUDE_DIR_QT}/scroll_widget.h
                ${SRC_DIR_CORE}/data_json/JsonUnloader.cpp
                ${SRC_DIR_CORE}/models/Trip.cpp
                ${SRC_DIR_CORE}/models/TripComponent.cpp
                ${SRC_DIR_CORE}/models/TripDay.cpp
                ${SRC_DIR_CORE}/planner/ScheduleBuilder.cpp
                ${SRC_DIR_CORE}/services/Finder.cpp
                ${SRC_DIR_CORE}/services/IntercityTransfer.cpp
                ${SRC_DIR_CORE}/services/IntracityTransfer.cpp
                ${SRC_DIR_CORE}/utils/DateTimeUtils.cpp
                ${INCLUDE_DIR_CORE}/data_json/JsonUnloader.h
                ${INCLUDE_DIR_CORE}/models/Trip.h
                ${INCLUDE_DIR_CORE}/models/TripComponent.h
                ${INCLUDE_DIR_CORE}/models/TripDay.h
                ${INCLUDE_DIR_CORE}/planner/ScheduleBuilder.h
                ${INCLUDE_DIR_CORE}/services/Finder.h
                ${INCLUDE_DIR_CORE}/services/IntercityTransfer.h
                ${INCLUDE_DIR_CORE}/services/IntracityTransfer.h
                ${INCLUDE_DIR_CORE}/utils/DateTimeUtils.h
                ${CMAKE_SOURCE_DIR}/src/start_create.cpp
                ${CMAKE_SOURCE_DIR}/include/start_create.h)


target_include_directories(Tul PRIVATE ${INCLUDE_DIR_QT} ${INCLUDE_DIR_CORE} ${SRC_DIR_QT} ${SRC_DIR_CORE} ${CMAKE_SOURCE_DIR}/include  ${CMAKE_SOURCE_DIR}/src)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../ui") #установили значение для переменной, которую CMake будет использовтаь при поиске файлов интерфейсов

target_link_libraries(Tul PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        nlohmann_json::nlohmann_json 
        cpr::cpr) #линкует найденные библиотеки Qt к программе

