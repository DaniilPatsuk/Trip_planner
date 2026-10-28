#include "ScheduleBuilder.h"

// Метод добавляет любой тип события в расписание
bool ScheduleBuilder::AddAnyTypeTripComponent(const TripComponent &trip_component)
{
    if ((trip_component.start_time < trip->trip_start || trip_component.GetEndTime() > trip->trip_end) && trip_component.type != TripComponentType::Home)
    {
        return false;
        // throw std::runtime_error("Дата компонента поездки " + trip_component.name + " выходит за рамки поездки");
    }
    std::tm tm = *std::localtime(&trip_component.start_time);
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    time_t start_of_day = std::mktime(&tm);
    time_t end_of_day = start_of_day + 86399;

    const auto &day = trip->schedules[FormatDate_to_str(trip_component.start_time)];

    if (trip_component.GetEndTime() > end_of_day)
    {
        TripComponent first_part = trip_component;
        first_part.duration = (end_of_day - trip_component.start_time + 1);
        TripComponent second_part = trip_component;
        second_part.start_time = end_of_day + 1;
        second_part.duration = trip_component.duration - first_part.duration;
        if (!trip->schedules[FormatDate_to_str(first_part.start_time)].TDIntersects(first_part) && !trip->schedules[FormatDate_to_str(second_part.start_time)].TDIntersects(second_part))
        {
            auto pair_first_part = finder->FindNeighbors(day, trip_component.start_time);
            auto pair_second_part = finder->FindNeighbors(day, trip_component.GetEndTime());
            if (intracitytransfer->CheckTimeRoad(first_part, pair_first_part) && intracitytransfer->CheckTimeRoad(second_part, pair_second_part))
            {
                trip->schedules[FormatDate_to_str(first_part.start_time)].AddTripComponent(first_part);
                if (second_part.start_time <= trip->trip_end)
                {
                    trip->schedules[FormatDate_to_str(second_part.start_time)].AddTripComponent(second_part);
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
            // throw std::runtime_error("Пересечение событий!");
        }
    }
    else
    {
        if (!trip->schedules[FormatDate_to_str(trip_component.start_time)].TDIntersects(trip_component))
        {
            auto pair = finder->FindNeighbors(day, trip_component.start_time);
            if (intracitytransfer->CheckTimeRoad(trip_component, pair))
            {
                trip->schedules[FormatDate_to_str(trip_component.start_time)].AddTripComponent(trip_component);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
            // throw std::runtime_error("Пересечение событий!");
        }
    }
}

// Метод добавляет жёсткое событие (AllFix) в расписание.
void ScheduleBuilder::AddFixTripComponent(TripComponent &trip_component)
{
    if(AddAnyTypeTripComponent(trip_component))
    {
        return;
    }
}

void ScheduleBuilder::AddFlexibleTripComponent(TripComponent &trip_component)
{
    auto windows = finder->FindFreeWindows(trip->schedules);
    auto filtered_windows = finder->FilterWindows(trip_component, windows);

    for (const auto &window : filtered_windows)
    {
        time_t window_date = FormatDate_to_time_t(window.date_key);
        time_t proposed_start = window.start;
        if (trip_component.type == TripComponentType::DayFix ||
            trip_component.type == TripComponentType::NoneFix)
        {
            proposed_start = std::max(window.start, window_date + trip_component.start_period_time);
        }
        else if (trip_component.type == TripComponentType::TimeFix)
        {
            proposed_start = window_date + trip_component.time;
        }
        trip_component.start_time = proposed_start;
        if (trip_component.GetEndTime() > window.end)
        {
            continue;
        }
        if(AddAnyTypeTripComponent(trip_component)) 
        {
            return;
        }
    }
}

// Блокирует время сна на каждый день поездки.
void ScheduleBuilder::SetSleepTime(TripComponent &habitation)
{
    for (time_t current_day = trip->trip_start; current_day <= trip->trip_end - 86400; current_day += 86400)
    {
        habitation.start_time = current_day + habitation.time;
        AddAnyTypeTripComponent(habitation);
    }
}

// Метод выводит всё расписание поездки в консоль.
void ScheduleBuilder::PrintSchedule() const
{
    for (const auto &day : trip->schedules)
    {
        std::cout << day.first << std::endl;
        if (day.second.GetTripComponents().size() > 0)
        {
            for (const auto &trip_component : day.second.GetTripComponents())
            {
                std::cout << FormatTime_to_str(trip_component.start_time) << " - " << FormatTime_to_str(trip_component.GetEndTime()) << " " << trip_component.name << std::endl;
            }
        }
        else
        {
            std::cout << "empty" << std::endl;
        }
    }
}

// Метод инициализирует поездку.
void ScheduleBuilder::SetTripDates(time_t start_date, time_t end_date)
{
    trip->trip_start = start_date;
    trip->trip_end = end_date;
}

// Метод добавляет лучший трансфер (по времени) в поездку
void ScheduleBuilder::AddTransfer(std::string dep_city, std::string arr_city, time_t date, bool flag)
{
    std::vector<Transfer> flights = intercitytransfer->SearchAllTransports(dep_city, arr_city, date);
    if (flights.empty())
    {
        throw std::runtime_error("Спосмобов добраться из " + dep_city + " в " + arr_city + " не найдено");
    }
    
    bool find_transfer = false;
    for (const auto &flight : flights)
    {
        time_t arrival_time = ParseYandexDateTime(flight.arrival_time);
        std::tm *arr_tm = std::localtime(&arrival_time);
        time_t departure_time = ParseYandexDateTime(flight.departure_time);
        std::tm *dep_tm = std::localtime(&departure_time);
        if (flag)
        {
            if (dep_tm->tm_hour < 6 || dep_tm->tm_hour > 18)
                continue;
        }
        else
        {
            if (arr_tm->tm_hour < 6 || arr_tm->tm_hour > 18)
                continue;
        }
        TripComponent transfer;
        transfer.name = "Перелёт: " + dep_city + " -> " + arr_city + " (" + flight.number + ")";
        transfer.type = TripComponentType::AllFix;
        transfer.duration = flight.duration;
        transfer.latitude = flag ? flight.arrival_lat : flight.departure_lat;
        transfer.longitude = flag ? flight.arrival_lon : flight.departure_lon;
        transfer.start_time = departure_time;

        if (AddAnyTypeTripComponent(transfer))
        {
            find_transfer = true;
            return;
        }
    }
    if (!find_transfer)
    {
        throw std::runtime_error("Не удалось найти способо перезда из " + dep_city + " в " + arr_city + ", который не пересекается с расписанием");
    }
}

// Метод вызвыает метод AddStation у intercitytransfer
void ScheduleBuilder::AddStation(std::string city_name, City_data city_data)
{
    intercitytransfer->AddStation(city_name, city_data);
}