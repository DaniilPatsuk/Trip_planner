#pragma once
#include "string"
#include "vector"
#include "models/TripComponent.h"
#include "map"
#include "fstream"
#include "nlohmann/json.hpp"
#include "iomanip"
#include "utils/DateTimeUtils.h"

using namespace DateTimeUtils;

class JsonUnloader
{
public:
    // Метод класа JsonLoader, который загружает период поездки (дату начала и дату окончания)
    std::pair<time_t, time_t> UnloadTripPeriod(const std::string &filepath = "resources/trip.json");

    // Метод класа JsonLoader, который создает список событий по городам
    std::map<std::string, std::vector<TripComponent>> UnloadTripComponents(const std::string &filepath = "resources/trip.json");

    // Метод класа JsonLoader, который создает список мест проживаний по городам
    std::map<std::string, std::vector<TripComponent>> UnloadHabitations(const std::string &filepath = "resources/trip.json");
};