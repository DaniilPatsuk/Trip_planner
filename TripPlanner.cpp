#include "TripPlanner.h"
#include "iostream"
#include "iomanip"
#include <sstream>

// Метод инициализирует поездку.
void TripPlanner::SetTripDates(time_t start_date, time_t end_date)
{
    trip_start = start_date;
    trip_end = end_date;
    time_t current_date = start_date;
    while (current_date <= end_date)
    {
        schedules[FormatDate(current_date)];
        current_date += (60 * 60 * 24);
    }
}

//Метод добавляет любой тип события в расписание
void TripPlanner::AddAnyTypeEvent(const Event &event)
{
    if (event.start_time < trip_start || event.GetEndTime() > trip_end)
    {
        throw std::runtime_error("Дата события выходит за рамки поездки");
    }
    std::tm tm = *std::localtime(&event.start_time);
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    time_t start_of_day = std::mktime(&tm);
    time_t end_of_day = start_of_day + 86400;
    if (event.GetEndTime() > end_of_day)
    {
        Event first_part = event;
        first_part.duration = (end_of_day - event.start_time) / 60;

        Event second_part = event;
        second_part.start_time = end_of_day;
        second_part.duration = event.duration - first_part.duration;
        if (!schedules[FormatDate(first_part.start_time)].DIntersects(first_part) && !schedules[FormatDate(second_part.start_time)].DIntersects(second_part))
        {
            schedules[FormatDate(event.start_time)].AddEvent(first_part);
            schedules[FormatDate(second_part.start_time)].AddEvent(second_part);
        }
        else
        {
            throw std::runtime_error("Пересечение событий!");
        }
    }
    else
    {
        schedules[FormatDate(event.start_time)].AddEvent(event);
    }
}
// Метод добавляет жёсткое событие (AllFix) в расписание.
void TripPlanner::AddFixEvent(const Event &event)
{
    if (event.type != EventType::AllFix)
    {
        throw std::runtime_error("Ожидался тип события AllFix");
    }
    AddAnyTypeEvent(event);
}

// Метод выводит всё расписание поездки в консоль.
void TripPlanner::PrintSchedule() const
{
    for (const auto &day : schedules)
    {
        std::cout << day.first << std::endl;
        if (day.second.GetEvents().size() > 0)
        {
            for (const auto &event : day.second.GetEvents())
            {
                std::cout << FormatTime(event.start_time) << " - " << FormatTime(event.GetEndTime()) << " " << event.name << std::endl;
            }
        }
        else
        {
            std::cout << "empty" << std::endl;
        }
    }
}

// Вспомогательный метод для форматирования времени в строку.
// Формат: "YYYY-MM-DD"
std::string TripPlanner::FormatDate(time_t t)
{
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d.%m.%Y");
    return oss.str();
}

// Вспомогательный метод для форматирования времени в строку.
// Формат: "HH:MM"
std::string TripPlanner::FormatTime(time_t t)
{
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M");
    return oss.str();
}

// Блокирует время сна на каждый день поездки.
void TripPlanner::SetSleepSchedule(int start_hour, int start_min, int duration)
{
    for (time_t current_day = trip_start; current_day <= trip_end; current_day += 86400)
    {
        Event sleep_event;
        sleep_event.type = EventType::Home;
        sleep_event.name = "Гостиница";
        sleep_event.is_sleep = true;
        sleep_event.start_time = current_day + start_hour * 3600 + start_min * 60;
        sleep_event.duration = duration;
        AddAnyTypeEvent(sleep_event);
    }
}
