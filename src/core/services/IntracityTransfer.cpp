#include "services/IntracityTransfer.h"

// Метод проверяет влазиет ли событие tripcomponent между парой соседних собитий pair по времени в пути
bool IntracityTransfer::CheckTimeRoad(const TripComponent &trip_component, std::pair<const TripComponent *, const TripComponent *> &pair)
{
    if (pair.first != nullptr)
    {
        int gap = trip_component.start_time - pair.first->GetEndTime();
        if (GetTravelTime(pair.first->latitude, pair.first->longitude, trip_component.latitude, trip_component.longitude) > gap)
        {
            return false;
        }
    }
    if (pair.second != nullptr)
    {
        int gap = pair.second->start_time - trip_component.GetEndTime();
        if (GetTravelTime(pair.second->latitude, pair.second->longitude, trip_component.latitude, trip_component.longitude) > gap)
        {
            return false;
        }
    }
    return true;
}

// Рассчитывает время в пути между двумя точками.
int IntracityTransfer::GetTravelTime(double lat1, double lon1, double lat2, double lon2)
{
    if (lat1 == lat2 && lon1 == lon2)
    {
        return 0;
    }
    else
    {
        std::ostringstream url_stream;
        url_stream << "http://router.project-osrm.org/route/v1/driving/"
                   << lon1 << "," << lat1 << ";"
                   << lon2 << "," << lat2
                   << "?overview=false";
        std::string url = url_stream.str();
        cpr::Response r = cpr::Get(cpr::Url(url));
        if (r.status_code != 200)
        {
            throw std::runtime_error("Ошибка сети при запросе к OSRM. Код ответа: " + std::to_string(r.status_code));
        }
        nlohmann::json j;
        try
        {
            j = nlohmann::json::parse(r.text);
        }
        catch (const nlohmann::json::parse_error &e)
        {
            throw std::runtime_error("Ошибка парсинга JSON ответа от OSRM");
        }
        return j["routes"][0]["duration"];
    }
}
