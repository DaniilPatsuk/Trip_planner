#include "TripComponent.h"

// Метод возвращает время начала события.
std::time_t SetStartTime(std::time_t date_start,  int time_start_min)
{
    return date_start + time_start_min;
}

// Метод возвращает время окончания события.
std::time_t TripComponent::GetEndTime() const
{
    return start_time + duration;
}

// Метод проверяет, пересекается ли это событие с другим.
// return true если события пересекаются
bool TripComponent::TCIntersects(const TripComponent &other) const
{
    if (start_time < other.GetEndTime() && other.start_time < this->GetEndTime())
    {
        return true;
    }
    else
    {
        return false;
    }
}
