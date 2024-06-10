#include "Time.h"

Time::Time(std::string_view timeString)
{
    fromString(timeString);
}

Time Time::operator+(const Time &t) const
{
    int totalSec1 = hours * SEC_IN_HOUR + minutes * SEC_IN_MIN + seconds;
    int totalSec2 = t.hours * SEC_IN_HOUR + t.minutes * SEC_IN_MIN + t.seconds;
    int totalSec = totalSec1 + totalSec2;

    Time result;
    result.hours = (totalSec / SEC_IN_HOUR) % 24;
    result.minutes = (totalSec % SEC_IN_HOUR) / SEC_IN_MIN;
    result.seconds = totalSec % SEC_IN_MIN;

    return result;
}

Time Time::operator-(const Time &t) const
{
    int totalSec1 = hours * SEC_IN_HOUR + minutes * SEC_IN_MIN + seconds;
    int totalSec2 = t.hours * SEC_IN_HOUR + t.minutes * SEC_IN_MIN + t.seconds;
    int totalSec = totalSec1 - totalSec2;

    if (totalSec < 0)
        totalSec += 24 * SEC_IN_HOUR;

    Time result;
    result.hours = (totalSec / SEC_IN_HOUR) % 24;
    result.minutes = (totalSec % SEC_IN_HOUR) / SEC_IN_MIN;
    result.seconds = totalSec % SEC_IN_MIN;

    return result;
}

Time Time::operator/(int divisor) const
{
    int totalSec = hours * SEC_IN_HOUR + minutes * SEC_IN_MIN + seconds;
    totalSec /= divisor;

    Time result;
    result.hours = (totalSec / SEC_IN_HOUR) % 24;
    result.minutes = (totalSec % SEC_IN_HOUR) / SEC_IN_MIN;
    result.seconds = totalSec % SEC_IN_MIN;

    return result;
}
