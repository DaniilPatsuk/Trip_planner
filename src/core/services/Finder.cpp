#include "services/Finder.h"

// Найти предыдущее и следующее событие относительно заданного времени в дне.
std::pair<const TripComponent *, const TripComponent *> Finder::FindNeighbors(const TripDay &day, time_t time_point)
{
    const TripComponent *before_time_point = nullptr;
    const TripComponent *after_time_point = nullptr;
    for (const auto &trip_component : day.GetTripComponents())
    {
        if (trip_component.GetEndTime() <= time_point)
        {
            before_time_point = &trip_component;
        }
        else if (trip_component.start_time >= time_point)
        {
            after_time_point = &trip_component;
            break;
        }
    }
    return std::make_pair(before_time_point, after_time_point);
}

// Находит все свободные окна в расписании
std::vector<TimeWindow> Finder::FindFreeWindows(std::map<std::string, TripDay> scheldules)
{
    std::vector<TimeWindow> windows;
    const int MIN_GAP = 30 * 60;
    for (const auto &[day, schedule] : scheldules)
    {
        const auto &events = schedule.GetTripComponents();
        time_t day_start = FormatDate_to_time_t(day);
        time_t day_end = day_start + 86400;

        // Если событий в этот день нет вообще — весь день свободен
        if (events.empty())
        {
            TimeWindow w;
            w.date_key = day;
            w.start = day_start;
            w.end = day_end;
            windows.push_back(w);
            continue;
        }

        // Окно ДО первого события
        if (events[0].start_time - day_start >= MIN_GAP)
        {
            TimeWindow w;
            w.date_key = day;
            w.start = day_start;
            w.end = events[0].start_time;
            windows.push_back(w);
        }

        // Окна МЕЖДУ событиями
        for (size_t i = 0; i + 1 < events.size(); ++i)
        {
            time_t gap_start = events[i].GetEndTime();
            time_t gap_end = events[i + 1].start_time;

            if (gap_end - gap_start >= MIN_GAP)
            {
                TimeWindow w;
                w.date_key = day;
                w.start = gap_start;
                w.end = gap_end;
                windows.push_back(w);
            }
        }

        // Окно ПОСЛЕ последнего события
        if (day_end - events.back().GetEndTime() >= MIN_GAP)
        {
            TimeWindow w;
            w.date_key = day;
            w.start = events.back().GetEndTime();
            w.end = day_end;
            windows.push_back(w);
        }
    }

    return windows;
}

// Фильтрует окна по ограничениям события (только для DayFix, TimeFix, NoneFix)
std::vector<TimeWindow> Finder::FilterWindows(const TripComponent &event, const std::vector<TimeWindow> &windows)
{
    std::vector<TimeWindow> filtered_windows;
    for (const auto &window : windows)
    {
        if (window.end - window.start < event.duration)
        {
            continue;
        }

        if (event.type == TripComponentType::DayFix)
        {
            if ((window.end >= event.start_period_time + FormatDate_to_time_t(window.date_key) && window.start <= event.end_period_time + FormatDate_to_time_t(window.date_key)) &&
                FormatDate_to_time_t(window.date_key) == event.date)
                filtered_windows.push_back(window);
        }
        else if (event.type == TripComponentType::TimeFix)
        {
            if ((FormatDate_to_time_t(window.date_key) >= event.start_period_date &&
                 FormatDate_to_time_t(window.date_key) <= event.end_period_date) &&
                (window.end >= FormatDate_to_time_t(window.date_key) + event.time + event.duration && window.start <= FormatDate_to_time_t(window.date_key) + event.time))
                filtered_windows.push_back(window);
        }
        else if (event.type == TripComponentType::NoneFix)
        {
            if ((FormatDate_to_time_t(window.date_key) >= event.start_period_date &&
                 FormatDate_to_time_t(window.date_key) <= event.end_period_date) &&
                (window.end >= FormatDate_to_time_t(window.date_key) + event.start_period_time && window.start <= FormatDate_to_time_t(window.date_key) + event.end_period_time))
                filtered_windows.push_back(window);
        }
    }
    return filtered_windows;
}