#pragma once
#include <string>
#include <chrono>
#include "ctime"

// Типы событий
enum class EventType
{
    AllFix,
    DayFix,
    TimeFix,
    NoneFix,
    Home
};

// Структура, описывающая одно событие в поездке.
struct Event
{
    std::string name;
    EventType type;
    std::time_t start_time;
    int duration;

    double latitude = 0.0;
    double longitude = 0.0;

    bool is_sleep = false;

    // Метод возвращает время окончания события.
    std::time_t GetEndTime() const;

    // Метод проверяет, пересекается ли это событие с другим.
    bool EIntersects(const Event &other) const;
};