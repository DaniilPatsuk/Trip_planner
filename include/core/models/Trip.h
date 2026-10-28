#pragma once
#include "map"
#include "string"
#include "ctime"
#include "models/TripDay.h"

// Главный класс планировщика поездки.
// Управляет расписаниями по дням.
class Trip
{
public:
    // Контейнер для хранения расписаний по дням.
    std::map<std::string, TripDay> schedules;

    time_t trip_start;
    time_t trip_end;
};