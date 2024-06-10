#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <string_view>

class Time
{
public:
    static constexpr int SEC_IN_HOUR = 3600;
    static constexpr int SEC_IN_MIN = 60;

    Time() = default;
    explicit Time(std::string_view timeString);
    ~Time() = default;

    Time &operator=(const Time &time) = default;
    auto operator<=>(const Time &t) const = default;

    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
    int getHours() const { return hours; }

    void setMinutes(int min) { minutes = min; }
    void setSeconds(int sec) { seconds = sec; }
    void setHours(int hrs) { hours = hrs; }

    Time operator+(const Time &t) const;
    Time operator/(int divisor) const;
    Time operator-(const Time &t) const;

    friend std::ostream &operator<<(std::ostream &os, const Time &t)
    {
        os << t.getHours() << ":" << t.getMinutes() << ":" << t.getSeconds();
        return os;
    }

private:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    void fromString(std::string_view timeString);
};

Time::Time(std::string_view timeString)
{
    fromString(timeString);
}

void Time::fromString(std::string_view timeString)
{
    std::istringstream ss(std::string(timeString.data()));
    char delim;
    ss >> hours >> delim >> minutes >> delim >> seconds;
}

Time Time::operator+(const Time &t) const
{
    Time result;
    result.seconds = this->seconds + t.seconds;
    result.minutes = this->minutes + t.minutes + result.seconds / SEC_IN_MIN;
    result.hours = this->hours + t.hours + result.minutes / SEC_IN_MIN;
    result.minutes %= SEC_IN_MIN;
    result.seconds %= SEC_IN_MIN;

    if (result.hours > 24)
        result.hours -= 24;

    if (result.minutes > SEC_IN_MIN)
    {
        result.minutes -= SEC_IN_MIN;
        result.hours += 1;
    }

    if (result.seconds > SEC_IN_MIN)
    {
        result.seconds -= SEC_IN_MIN;
        result.minutes += 1;
    }

    return result;
}

Time Time::operator/(const int t) const
{
    int secCount = this->hours * SEC_IN_HOUR + this->minutes * SEC_IN_MIN + this->seconds;
    secCount /= t;
    Time result;

    result.hours = secCount / SEC_IN_HOUR;
    result.minutes = (secCount % SEC_IN_HOUR) / SEC_IN_MIN;
    result.seconds = secCount % SEC_IN_MIN;

    return result;
}

Time Time::operator-(const Time &t) const
{
    Time result;
    result.seconds = this->seconds - t.seconds;
    result.minutes = this->minutes - t.minutes;
    result.hours = this->hours - t.hours;

    if (result.seconds < 0)
    {
        result.seconds += SEC_IN_MIN;
        result.minutes -= 1;
    }

    if (result.minutes < 0)
    {
        result.minutes += SEC_IN_MIN;
        result.hours -= 1;
    }

    if (result.hours < 0)
        result.hours += 24;

    return result;
}
