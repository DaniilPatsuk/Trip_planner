#include "utils/DateTimeUtils.h"

std::string DateTimeUtils::FormatDate_to_str(std::time_t t)
{
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y.%m.%d");
    return oss.str();
}

std::string DateTimeUtils::FormatTime_to_str(std::time_t t)
{
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M");
    return oss.str();
}

std::time_t DateTimeUtils::FormatDate_to_time_t(const std::string &date_str)
{
    std::tm tm = {};
    std::istringstream iss(date_str);
    iss >> std::get_time(&tm, "%Y.%m.%d");
    if (iss.fail())
    {
        throw std::runtime_error("Неверный формат даты: " + date_str);
    }
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    return std::mktime(&tm);
}

int DateTimeUtils::FormatTime_to_int(const std::string &time_str)
{
    std::tm tm = {};
    std::istringstream iss(time_str);
    iss >> std::get_time(&tm, "%H:%M");
    if (iss.fail())
    {
        throw std::runtime_error("Неверный формат времени: " + time_str);
    }
    return tm.tm_hour * 3600 + tm.tm_min * 60;
}

std::time_t DateTimeUtils::FormatDateTime_to_time_t(const std::string &datetime_str)
{
    std::tm tm = {};
    std::istringstream iss(datetime_str);
    iss >> std::get_time(&tm, "%Y.%m.%d %H:%M");
    if (iss.fail())
    {
        throw std::runtime_error("Неверный формат даты и времени: " + datetime_str);
    }
    return std::mktime(&tm);
}

std::time_t DateTimeUtils::ParseYandexDateTime(const std::string &datetime_str)
{
    std::tm tm = {};
    // Берем только первые 19 символов: "YYYY-MM-DDTHH:MM:SS"
    std::string clean_str = datetime_str.substr(0, 19);
    std::istringstream iss(clean_str);
    iss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S");
    if (iss.fail())
    {
        throw std::runtime_error("Неверный формат времени Яндекс: " + datetime_str);
    }
    return std::mktime(&tm);
}

// time_t -> "YYYY-MM-DD"
std::string  DateTimeUtils::FormatYandexTime(std::time_t t)
{
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    return oss.str();
}