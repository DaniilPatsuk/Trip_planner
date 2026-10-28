#pragma once
#include "ctime"
#include "string"
#include "sstream"
#include "iomanip"
#include "stdexcept"

namespace DateTimeUtils {

    // time_t -> "YYYY.MM.DD"
    std::string FormatDate_to_str(std::time_t t);

    // time_t -> "HH:MM"
    std::string FormatTime_to_str(std::time_t t);

    // "YYYY.MM.DD" -> time_t (начало дня, 00:00:00)
    std::time_t FormatDate_to_time_t(const std::string& date_str);

    // "HH:MM" -> секунды от начала суток
    int FormatTime_to_int(const std::string& time_str);

    // "YYYY.MM.DD HH:MM" -> time_t
    std::time_t FormatDateTime_to_time_t(const std::string& datetime_str);

    // "YYYY-MM-DDTHH:MM:SS+03:00" -> time_t
    std::time_t ParseYandexDateTime(const std::string& datetime_str); 

    // time_t -> "YYYY-MM-DD"
    std::string  FormatYandexTime(std::time_t t);
} 