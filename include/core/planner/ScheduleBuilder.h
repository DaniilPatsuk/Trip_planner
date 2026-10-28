#include "iostream"
#include "data_json/JsonUnloader.h"
#include "utils/DateTimeUtils.h"
#include "models/Trip.h"
#include "models/TripComponent.h"
#include "models/TripDay.h"
#include "services/Finder.h"
#include "services/IntracityTransfer.h"
#include "services/IntercityTransfer.h"

using namespace DateTimeUtils;

class ScheduleBuilder 
{
public:
    ScheduleBuilder()
    {
        trip = new Trip;
        finder = new Finder;
        intercitytransfer = new IntercityTransfer;
        intracitytransfer = new IntracityTransfer;
    };

    // Метод является оберткой над AddAnyTypeEvent
    // Добавляет жёсткое событие (AllFix) в расписание.
    void AddFixTripComponent(TripComponent &trip_component);

    // Метод является оберткой над AddAnyTypeEvent
    // Добавляет гибкое событие (DayFix, TimeFix, NoneFix) в расписание.
    void AddFlexibleTripComponent(TripComponent &trip_component);

    // Метод добавляет любой тип события в расписание
    bool AddAnyTypeTripComponent(const TripComponent &trip_component);

    // Блокирует время сна на каждый день поездки.
    void SetSleepTime(TripComponent& habitation);
    
    //Метод добавляет лучший трансфер (по времени) в поездку
    void AddTransfer(std::string dep_city, std::string arr_city, time_t date, bool flag);

    // Метод выводит всё расписание поездки в консоль.
    void PrintSchedule() const;

    // Метод инициализирует поездку.
    void SetTripDates(time_t start_date, time_t end_date);

    //Метод вызвыает метод AddStation у intercitytransfer
    void AddStation(std::string city_name, City_data city_data);

private:
    JsonUnloader* unloader;
    Trip* trip;
    Finder* finder;
    IntercityTransfer* intercitytransfer;
    IntracityTransfer* intracitytransfer;
};