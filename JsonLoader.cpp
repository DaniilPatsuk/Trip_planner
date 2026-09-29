#include "JsonLoader.h"
#include "fstream"
#include "nlohmann/json.hpp"
#include "iomanip"

// Загружает конфигурацию поездки из trip.json.
std::pair<time_t, time_t> JsonLoader::LoadTrip(const std::string &filepath)
{
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        throw std::runtime_error("trip file is missing");
    }
    nlohmann::json trip_data;
    file >> trip_data;
    return std::make_pair<time_t, time_t>(ParseDateTime(trip_data["trip"]["start_date"]), ParseDateTime(trip_data["trip"]["end_date"]));
}

// Загружает список событий из events.json.
std::vector<Event> JsonLoader::LoadEvents(const std::string &filepath)
{
    std::vector<Event> events;
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        throw std::runtime_error("events file is missing");
    }
    nlohmann::json events_data;
    file >> events_data;
    for (auto &event_data : events_data["events"])
    {
        Event event;
        event.name = event_data["name"];
        std::string type_str = event_data["type"];
        if (type_str == "AllFix")
            event.type = EventType::AllFix;
        else if (type_str == "DayFix")
            event.type = EventType::DayFix;
        else if (type_str == "TimeFix")
            event.type = EventType::TimeFix;
        else if (type_str == "NoneFix")
            event.type = EventType::NoneFix;
        event.start_time = ParseDateTime(event_data["datetime"]);
        event.duration = event_data["duration"];
        event.latitude = event_data["latitude"];
        event.longitude = event_data["longitude"];
        events.push_back(event);
    }
    return events;
}

// Вспомогательный метод для парсинга строки вида "YYYY-MM-DD HH:MM" в time_t.
time_t JsonLoader::ParseDateTime(const std::string &datetime_str)
{
    std::tm tm = {};
    std::istringstream iss(datetime_str);
    iss >> std::get_time(&tm, "%Y-%m-%d %H:%M");

    if (iss.fail())
    {
        throw std::runtime_error("Неверный формат даты в JSON: " + datetime_str);
    }
    return std::mktime(&tm);
}
