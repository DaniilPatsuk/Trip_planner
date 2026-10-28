#pragma once
#include "models/TripComponent.h"
#include "vector"
#include "stdexcept"
#include "algorithm"
#include "iostream"
#include "exception"

// Класс, хранящий расписание одного дня.
// Внутри хранит список событий, отсортированный по времени начала.
class TripDay
{
public:
    // Метод проверяет есть ли пересечение события event с события ми в течении дня
    // return true если пересечение найдено
    bool TDIntersects(const TripComponent &event);

    // Метод добавляет событие в расписание дня.
    void AddTripComponent(const TripComponent &event);

    // Метод возвращает константную ссылку на список событий дня.
    const std::vector<TripComponent> &GetTripComponents() const;

    // Список событий дня
    std::vector<TripComponent> trip_components;
};