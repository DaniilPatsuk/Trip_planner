#pragma once
#include "string"
#include "chrono"
#include "ctime"

// Типы событий
enum class TripComponentType
{
    AllFix,
    DayFix,
    TimeFix,
    NoneFix,
    Home
};

// Структура, описывающая одно событие в поездке.
class TripComponent
{
public:
    std::string name;
    TripComponentType type;
    int duration; // длительность события в секундах
    double latitude = 0.0;
    double longitude = 0.0;

    std::time_t start_time = 0;
    std::time_t date = 0;
    int time = 0;
    std::time_t start_period_date = 0;
    std::time_t end_period_date = 0;
    int start_period_time = 0;
    int end_period_time = 1439; 

    // Метод возвращает время начала события.
    std::time_t SetStartTime(std::time_t date_start,  int time_start);

    // Метод возвращает время окончания события.
    std::time_t GetEndTime() const;

    // Метод проверяет, пересекается ли это событие с другим.
    bool TCIntersects(const TripComponent &other) const;
};

