#pragma once
#include <string>
#include <vector>
#include "Event.h"

class JsonLoader
{
public:
    JsonLoader() = default;

    // Загружает конфигурацию поездки из trip.json.
    std::pair<time_t, time_t> LoadTrip(const std::string &filepath = "resources/trip.json");

    //Загружает список событий из events.json.
    std::vector<Event> LoadEvents(const std::string &filepath = "resources/events.json");

private:
    //Вспомогательный метод для парсинга строки вида "YYYY-MM-DD HH:MM" в time_t.
    time_t ParseDateTime(const std::string &datetime_str);
};