#pragma once
#include "DaySchedule.h"
#include <map>
#include <string>
#include "ctime"

// Главный класс планировщика поездки.
// Управляет расписаниями по дням.
class TripPlanner
{
public:
    // Метод инициализирует поездку.
    void SetTripDates(time_t start_date, time_t end_date);

    // Метод добавляет жёсткое событие (AllFix) в расписание.
    void AddFixEvent(const Event &event);

    //Метод добавляет любой тип события в расписание
    void AddAnyTypeEvent(const Event &event);

    // Метод выводит всё расписание поездки в консоль.
    void PrintSchedule() const;

    // Блокирует время сна на каждый день поездки.
    void SetSleepSchedule(int start_hour, int start_min, int duration);

private:
    // Контейнер для хранения расписаний по дням.
    std::map<std::string, DaySchedule> schedules;

    time_t trip_start;
    time_t trip_end;

    // Вспомогательный метод для форматирования даты в строку.
    // Формат: "YYYY-MM-DD"
    static std::string FormatDate(time_t t);

    // Вспомогательный метод для форматирования времени в строку.
    // Формат: "HH:MM"
    static std::string FormatTime(time_t t);
};