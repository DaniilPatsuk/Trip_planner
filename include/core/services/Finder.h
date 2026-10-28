#pragma once
#include "iostream"
#include "models/TripComponent.h"
#include "models/TripDay.h"
#include "models/Trip.h"
#include "vector"
#include "map"
#include "utils/DateTimeUtils.h"

using namespace DateTimeUtils;

struct TimeWindow
{
    time_t start;
    time_t end;
    std::string date_key;
};

class Finder
{
public:
    // Найти предыдущее и следующее событие относительно заданного времени в дне.
    std::pair<const TripComponent *, const TripComponent *> FindNeighbors(const TripDay &day, time_t time_point);

    // Находит все свободные окна в расписании
    std::vector<TimeWindow> FindFreeWindows(std::map<std::string, TripDay> scheldules);

    // Фильтрует окна по ограничениям события (только для DayFix, TimeFix, NoneFix)
    std::vector<TimeWindow> FilterWindows(const TripComponent &event, const std::vector<TimeWindow> &windows);
};