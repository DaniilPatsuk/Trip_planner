#include "TripDay.h"

//Метод проверяет есть ли пересечение события event с события ми в течении дня
//return true если пересечение найдено
bool TripDay::TDIntersects(const TripComponent &trip_component)
{
    for (const auto &e : trip_components)
    {
        if (trip_component.TCIntersects(e))
        {
            return true;
        }
    }
    return false;
};

// Метод добавляет событие в расписание дня.
void TripDay::AddTripComponent(const TripComponent &trip_component)
{
    if (TDIntersects(trip_component))
        throw std::runtime_error("Пересечение событий!");
    trip_components.push_back(trip_component);
    for (int i = 0; i < trip_components.size(); i++)
    {
        for (int j = 0; j < trip_components.size() - i - 1; j++)
        {
            if (trip_components[j].start_time > trip_components[j + 1].start_time)
            {
                std::swap(trip_components[j], trip_components[j + 1]);
            }
        }
    }
}

// Метод возвращает константную ссылку на список событий дня.
const std::vector<TripComponent> &TripDay::GetTripComponents() const
{
    return trip_components;
}