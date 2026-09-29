#include "Event.h"

// Метод возвращает время окончания события.
std::time_t Event::GetEndTime() const
{
    return start_time + duration * 60;
}

// Метод проверяет, пересекается ли это событие с другим.
// return true если события пересекаются
bool Event::EIntersects(const Event &other) const
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
