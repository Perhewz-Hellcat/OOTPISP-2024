#include "Time.h"

Time::Time(std::string_view timeString)
{
    std::stringstream ss(timeString.data());
    char delimiter;
    ss >> _hours >> delimiter >> _min >> delimiter >> _sec;
}

Time Time::operator+(const Time &t) const
{
    Time result;
    result._sec = this->_sec + t._sec;
    result._min = this->_min + t._min + result._sec / SEC_IN_MIN;
    result._hours = this->_hours + t._hours + result._min / SEC_IN_MIN;
    result._min %= SEC_IN_MIN;
    result._sec %= SEC_IN_MIN;

    if (result._hours > 24)
        result._hours -= 24;

    if (result._min > SEC_IN_MIN)
    {
        result._min -= SEC_IN_MIN;
        result._hours += 1;
    }

    if (result._sec > SEC_IN_MIN)
    {
        result._sec -= SEC_IN_MIN;
        result._min += 1;
    }

    return result;
}

Time Time::operator-(const Time &t) const
{
    Time result;
    result._sec = this->_sec - t._sec;
    result._min = this->_min - t._min;
    result._hours = this->_hours - t._hours;

    if (result._sec < 0)
    {
        result._sec += SEC_IN_MIN;
        result._min -= 1;
    }

    if (result._min < 0)
    {
        result._min += SEC_IN_MIN;
        result._hours -= 1;
    }

    if (result._hours < 0)
        result._hours += 24;

    return result;
}

Time Time::operator/(const int t) const
{
    int secCount = this->_hours * SEC_IN_HOUR + this->_min * SEC_IN_MIN + this->_sec;
    secCount /= t;
    Time result;

    result._hours = secCount / SEC_IN_HOUR;
    result._min = (secCount % SEC_IN_HOUR) / SEC_IN_MIN;
    result._sec = secCount % SEC_IN_MIN;

    return result;
}