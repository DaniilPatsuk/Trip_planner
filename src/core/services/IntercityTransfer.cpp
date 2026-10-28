#include "services/IntercityTransfer.h"

// Универсальный поиск (пока только самолеты)
std::vector<Transfer> IntercityTransfer::SearchAllTransports(const std::string &from_city, const std::string &to_city, time_t date)
{
    std::vector<Transfer> all_transfers;

    auto flights = SearchFlights(from_city, to_city, date);
    for (auto i : flights)
    {
        all_transfers.push_back(i);
    }
    return all_transfers;
}

// Основной метод поиска рейсов
std::vector<Transfer> IntercityTransfer::SearchFlights(const std::string &from_city, const std::string &to_city, time_t date)
{
    std::vector<Transfer> transfers;
    std::string from_code = GetStationCode(from_city);
    std::string to_code = GetStationCode(to_city);
    std::string date_str = FormatYandexTime(date);

    std::string url = YANDEX_API_URL +
                      "?apikey=" + YANDEX_API_KEY +
                      "&format=json" +
                      "&from=" + from_code +
                      "&to=" + to_code +
                      "&date=" + date_str +
                      "&transport_types=plane" +
                      "&limit=20";

    cpr::Response r = cpr::Get(cpr::Url{url});
    std::cout<<url<<std::endl;
    if (r.status_code != 200)
    {
        std::cerr << "Ошибка API: " << r.status_code << std::endl;
        return transfers;
    }
    nlohmann::json j = nlohmann::json::parse(r.text);

    if (j.contains("segments") && j["segments"].is_array())
    {
        for (const auto &seg : j["segments"])
        {
            Transfer t;
            t.transport_type = "flight";
            t.departure_city = from_city;
            t.arrival_city = to_city;

            //Номер рейса и авиакомпания (ищи внутри seg["thread"])
            t.number = seg["thread"].value("number", "Неизвестно");
            if (seg["thread"].contains("carrier"))
            {
                t.carrier = seg["thread"]["carrier"].value("title", "Неизвестно");
            }

            //Время вылета и прилёта (ищи в seg["departure"] и seg["arrival"])
            t.departure_time = seg["departure"].get<std::string>();
            t.arrival_time = seg["arrival"].get<std::string>();

            //Названия аэропортов (ищи в seg["from"]["title"] и seg["to"]["title"])
            // t.departure_city = seg["from"].value("title", "");
            // t.arrival_city = seg["to"].value("title", "");

            //Длительность (Яндекс отдает в секундах, раздели на 60)
            if (seg.contains("duration"))
            {
                t.duration = seg["duration"].get<int>();
            }

            t.arrival_lat = GetStationCoordinates(GetStationCode(t.arrival_city)).first;
            t.arrival_lon = GetStationCoordinates(GetStationCode(t.arrival_city)).second;
            t.departure_lat = GetStationCoordinates(GetStationCode(t.departure_city)).first;
            t.departure_lon = GetStationCoordinates(GetStationCode(t.departure_city)).second;

            transfers.push_back(t);
        }
    }
    return transfers;
}

//Вспомогательный метод: получение координат по коду станции
std::pair<double, double> IntercityTransfer::GetStationCoordinates(const std::string &station_code)
{
    for (auto i : cities)
    {
        if(i.second.code == station_code)
        {
            return std::make_pair(i.second.lat, i.second.lon);
        }
    }
    throw std::runtime_error("Неизвестный код города : " + station_code);; 
}

//Получение кода станции по названию города
std::string IntercityTransfer::GetStationCode(const std::string &city_name)
{
    for (auto i : cities)
    {
        if(i.first == city_name)
        {
            return i.second.code;
        }
    }
    throw std::runtime_error("Неизвестный город : " + city_name);
}

//Метод для добавления объекта City_data в слварь cities
void IntercityTransfer::AddStation(std::string city_name, City_data city_data)
{
    cities[city_name] = city_data;
}