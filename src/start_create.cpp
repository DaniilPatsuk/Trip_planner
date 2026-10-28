#include "start_create.h"

void start_create()
{
    try
    {
        setlocale(LC_ALL, "Russian");
        ScheduleBuilder *schedule_builder = new ScheduleBuilder;
        JsonUnloader *unloader = new JsonUnloader;
        auto [start_date, end_date] = unloader->UnloadTripPeriod("D:/skillbox-projects/trip_planner/resources/trip.json");
        std::cout<<"1"<<std::endl;
        auto habitations = unloader->UnloadHabitations("D:/skillbox-projects/trip_planner/resources/trip.json");
        std::cout<<"2"<<std::endl;
        auto trip_components = unloader->UnloadTripComponents("D:/skillbox-projects/trip_planner/resources/trip.json");
        std::cout<<"3"<<std::endl;
        schedule_builder->SetTripDates(start_date, end_date);

        for (const auto &[city_name, habs] : habitations)
        {
            if (!habs.empty())
            {
                for (auto habitation : habs)
                {
                    schedule_builder->SetSleepTime(habitation);
                }
            }
        }

        for (auto &[city_name, trip_comps] : trip_components)
        {
            for (auto &trip_component : trip_comps)
            {
                if (trip_component.type == TripComponentType::AllFix)
                {
                    schedule_builder->AddFixTripComponent(trip_component);
                }
                else
                {
                    schedule_builder->AddFlexibleTripComponent(trip_component);
                }
            }
        }

        City_data city1;
        city1.code = "s9600213";
        city1.station_name = "Mscow-Svo";
        city1.lat = 55.7558;
        city1.lon = 37.6173;
        schedule_builder->AddStation("Moscow", city1);

        City_data city2;
        city2.code = "s9600366";
        city2.station_name = "Saint-Petersburg-Plk";
        city2.lat = 59.9343;
        city2.lon = 30.3351;
        schedule_builder->AddStation("Saint-Petersburg", city2);

        schedule_builder->AddTransfer("Moscow", "Saint-Petersburg", start_date, true);
        schedule_builder->AddTransfer("Saint-Petersburg", "Moscow", end_date, false);

        schedule_builder->PrintSchedule();
    }
    catch (std::exception &ex)
    {
        std::cout<<ex.what();
    }

}