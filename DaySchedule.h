#pragma once
#include "Event.h"
#include <vector>
#include <stdexcept>
#include <algorithm>

// Класс, хранящий расписание одного дня.
// Внутри хранит список событий, отсортированный по времени начала.
class DaySchedule
{
public:
    //Метод проверяет есть ли пересечение события event с события ми в течении дня
    //return true если пересечение найдено
    bool DIntersects(const Event &event);
    // Метод добавляет событие в расписание дня.
    void AddEvent(const Event &event);

    // Метод возвращает константную ссылку на список событий дня.
    const std::vector<Event> &GetEvents() const;

private:
    std::vector<Event> events; // Список событий дня
};