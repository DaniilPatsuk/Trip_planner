#pragma once
#include "iostream"
#include "vector"
#include "map"
#include "DateTimeUtils.h"
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"

using namespace DateTimeUtils;

// Универсальная структура для любого вида транспорта
struct Transfer
{
    std::string transport_type; // "flight", "train", "bus", "car"
    std::string number;         // номер рейса / поезда / маршрута
    std::string carrier;        // авиакомпания / РЖД / перевозчик

    std::string departure_city; // город отправления
    std::string arrival_city;   // город прибытия

    std::string departure_time; // "YYYY-MM-DD HH:MM"
    std::string arrival_time;   // "YYYY-MM-DD HH:MM"

    int duration = 0; // длительность в пути

    double departure_lat = 0.0;
    double departure_lon = 0.0;
    double arrival_lat = 0.0;
    double arrival_lon = 0.0;
};

struct City_data
{
    std::string station_name;
    std::string code;
    double lat = 0.0;
    double lon = 0.0;
};

class IntercityTransfer
{
public:
    const std::string YANDEX_API_KEY = "5d2b221f-bafa-472b-8f38-e27f9c71f0a9";
    const std::string YANDEX_API_URL = "https://api.rasp.yandex.net/v3.0/search/";
    // Универсальный поиск (пока только самолеты)
    std::vector<Transfer> SearchAllTransports(const std::string &from_city, const std::string &to_city, time_t date);

    // Основной метод поиска рейсов
    std::vector<Transfer> SearchFlights(const std::string &from_city, const std::string &to_city, time_t date);

    // Метод для получения координат по коду станции
    std::pair<double, double> GetStationCoordinates(const std::string &station_code);

    // Методл для получения кода станции по названию города
    std::string GetStationCode(const std::string &station_name);

    // Метод для добавления объекта City_data в слварь cities
    void AddStation(std::string city_name, City_data city_data);

    std::map<std::string, City_data> cities;
};