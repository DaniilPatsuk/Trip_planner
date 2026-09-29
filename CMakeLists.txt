cmake_minimum_required(VERSION 3.10)
project(trip_planner)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# ВАЖНО: перечисли здесь ВСЕ файлы с кодом, включая главный (test.cpp или main.cpp)
add_subdirectory(nlohmann_json)

add_executable(Tul
    test.cpp                # Твой главный файл с функцией main()
    Event.cpp           # Реализация Event
    DaySchedule.cpp     # Реализация DaySchedule
    TripPlanner.cpp     # Реализация TripPlanner\
    Event.h           # Реализация Event
    DaySchedule.h     # Реализация DaySchedule
    TripPlanner.h
    JsonLoader.h
    JsonLoader.cpp
)

target_link_libraries(Tul PRIVATE 
    nlohmann_json::nlohmann_json 
)