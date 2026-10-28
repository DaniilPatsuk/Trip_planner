#include "JsonUnloader.h"

std::pair<time_t, time_t> JsonUnloader::UnloadTripPeriod(const std::string &filepath)
{
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        throw std::runtime_error("Файл поездки не найден");
    }
    nlohmann::json trip_data;
    file >> trip_data;
    return std::make_pair<time_t, time_t>(FormatDate_to_time_t(trip_data["date"]["start_date"]), FormatDate_to_time_t(trip_data["date"]["end_date"])+86399);
}

const nlohmann::json &getCityObj(const nlohmann::json &obj, const std::string &key)
{
    for (auto it = obj.begin(); it != obj.end(); ++it)
    {
        std::string k = it.key();
        if (k == key)
        {
            return it.value();
        }
    }
    throw std::runtime_error("Ключ не найден в JSON: " + key);
}

std::map<std::string, std::vector<TripComponent>> JsonUnloader::UnloadTripComponents(const std::string &filepath)
{
    std::map<std::string, std::vector<TripComponent>> events_map;
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        throw std::runtime_error("Файл поездки не найден");
    }
    nlohmann::json trip_data;
    file >> trip_data;
    const auto &city_obj = getCityObj(trip_data, "city");
    for (const auto &[city_name, inner_data] : city_obj.items())
    {
        if (inner_data.contains("activities"))
        {
            for (const auto &event_data : inner_data["activities"])
            {
                TripComponent event;
                event.name = event_data["name"];
                event.duration = event_data["duration"].get<int>() * 60;
                event.latitude = event_data["latitude"];
                event.longitude = event_data["longitude"];

                std::string type_str = event_data["type"];
                if (type_str == "AllFix")
                {
                    event.type = TripComponentType::AllFix;
                    event.start_time = FormatDate_to_time_t(event_data["date"]) + FormatTime_to_int(event_data["time"]);
                }
                else if (type_str == "DayFix")
                {
                    event.type = TripComponentType::DayFix;
                    event.date = FormatDate_to_time_t(event_data["date"]);
                    event.start_period_time = FormatTime_to_int(event_data["start_time"]);
                    event.end_period_time = FormatTime_to_int(event_data["end_time"]);
                }
                else if (type_str == "TimeFix")
                {
                    event.type = TripComponentType::TimeFix;
                    event.time = FormatTime_to_int(event_data["time"]);
                    event.start_period_date = FormatDate_to_time_t(event_data["start_date"]);
                    event.end_period_date = FormatDate_to_time_t(event_data["end_date"]);
                }
                else if (type_str == "NoneFix")
                {
                    event.type = TripComponentType::NoneFix;
                    event.start_period_time = FormatTime_to_int(event_data["start_time"]);
                    event.end_period_time = FormatTime_to_int(event_data["end_time"]);
                    event.start_period_date = FormatDate_to_time_t(event_data["start_date"]);
                    event.end_period_date = FormatDate_to_time_t(event_data["end_date"]);
                }
                events_map[city_name].push_back(event);
            }
        }
    }
    return events_map;
}

std::map<std::string, std::vector<TripComponent>> JsonUnloader::UnloadHabitations(const std::string &filepath)
{
    std::map<std::string, std::vector<TripComponent>> habitations_map;
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        throw std::runtime_error("Файл поездки не найден");
    }
    nlohmann::json trip_data;
    file >> trip_data;
    const auto &city_obj = getCityObj(trip_data, "city");
    for (const auto &[city_name, inner_data] : city_obj.items())
    {
        if (inner_data.contains("habitations"))
        {
            for (const auto &hab_data : inner_data["habitations"])
            {
                TripComponent habitation;
                habitation.name = hab_data["name"];
                habitation.type = TripComponentType::Home;
                habitation.time = FormatTime_to_int(hab_data["time"]);
                habitation.duration = hab_data["duration"].get<int>() * 60;
                habitation.latitude = hab_data["latitude"];
                habitation.longitude = hab_data["longitude"];
                habitations_map[city_name].push_back(habitation);
            }
        }
    }
    return habitations_map;
}
