#include "DaySchedule.h"
#include "iostream"
#include "exception"

//Метод проверяет есть ли пересечение события event с события ми в течении дня
//return true если пересечение найдено
bool DaySchedule::DIntersects(const Event &event)
{
    for (const auto &e : events)
    {
        if (event.EIntersects(e))
        {
            return true;
        }
    }
    return false;
}

// Метод добавляет событие в расписание дня.
void DaySchedule::AddEvent(const Event &event)
{
    if (DIntersects(event))
        throw std::runtime_error("Пересечение событий!");
    events.push_back(event);
    for (int i = 0; i < events.size(); i++)
    {
        for (int j = 0; j < events.size() - i - 1; j++)
        {
            if (events[j].start_time > events[j + 1].start_time)
            {
                std::swap(events[j], events[j + 1]);
            }
        }
    }
}

// Метод возвращает константную ссылку на список событий дня.
const std::vector<Event> &DaySchedule::GetEvents() const
{
    return events;
}