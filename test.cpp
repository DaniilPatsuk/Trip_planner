#include "TripPlanner.h"
#include "iostream"
#include "ctime"
#include "JsonLoader.h"

// Функция-помощник для создания time_t из компонентов даты

time_t MakeTimeT(int year, int month, int day, int hour, int min)
{
    std::time_t t = std::time(nullptr);
    std::tm *tm = std::localtime(&t);
    tm->tm_year = year - 1900;
    tm->tm_mon = month - 1;
    tm->tm_mday = day;
    tm->tm_hour = hour;
    tm->tm_min = min;
    return std::mktime(tm);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    TripPlanner planner;
    JsonLoader loader;

    std::cout << "\n[1] Загрузка конфигурации поездки..." << std::endl;
    try
    {
        auto [start_date, end_date] = loader.LoadTrip("resources/trip.json");
        std::cout<<"lksaldkfjasldkf]\n";
        planner.SetTripDates(start_date, end_date);
        std::cout << "Даты поездки успешно установлены." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "КРИТИЧЕСКАЯ ОШИБКА: " << e.what() << std::endl;
        std::cerr << "Программа не может работать без файла конфигурации." << std::endl;
        return 1;
    }

    std::cout << "\n[2] Установка расписания сна (23:00, длительность 8 часов)..." << std::endl;
    planner.SetSleepSchedule(10, 30, 120);
    std::cout << "Время сна заблокировано на все дни поездки." << std::endl;

    std::cout << "\n[3] Загрузка и обработка событий..." << std::endl;
    try
    {
        std::vector<Event> events = loader.LoadEvents("resources/events.json");
        std::cout << "Всего событий в файле: " << events.size() << std::endl;

        int success_count = 0;
        int error_count = 0;

        for (const auto &event : events)
        {
            try
            {
                planner.AddFixEvent(event);
                std::cout << "  [OK] Добавлено: " << event.name << std::endl;
                success_count++;
            }
            catch (const std::runtime_error &e)
            {
                std::cerr << "  [ОШИБКА] Событие '" << event.name << "' отклонено: " << e.what() << std::endl;
                error_count++;
            }
        }

        std::cout << "\nИтог добавления: Успешно - " << success_count
                  << ", Отклонено - " << error_count << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "КРИТИЧЕСКАЯ ОШИБКА: " << e.what() << std::endl;
        return 1;
    }

    // === Шаг 4: Вывод итогового расписания ===
    std::cout << "\n[4] Итоговое расписание поездки:" << std::endl;
    planner.PrintSchedule();

    std::cout << "\nПрограмма успешно завершена!" << std::endl;
    return 0;
}
