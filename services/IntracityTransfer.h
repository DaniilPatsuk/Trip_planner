#pragma once
#include "iostream"
#include "TripComponent.h"
#include "sstream"
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"

class IntracityTransfer
{
public:
    // Метод проверяет влазиет ли событие tripcomponent между парой соседних собитий pair по времени в пути
    bool CheckTimeRoad(const TripComponent &trip_component, std::pair<const TripComponent *, const TripComponent *> &pair);

    // Рассчитывает время в пути между двумя точками.
    int GetTravelTime(double lat1, double lon1, double lat2, double lon2);
};