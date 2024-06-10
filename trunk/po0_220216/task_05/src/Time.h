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
    std::istringstream ss(std::string(timeString));
    char delim;
    ss >> hours >> delim >> minutes >> delim >> seconds;
}

Time Time::operator+(const Time &t) const
{
    int totalSec = (hours + t.hours) * SEC_IN_HOUR + (minutes + t.minutes) * SEC_IN_MIN + (seconds + t.seconds);
    int hrs = totalSec / SEC_IN_HOUR;
    int mins = (totalSec % SEC_IN_HOUR) / SEC_IN_MIN;
    int secs = totalSec % SEC_IN_MIN;
    return Time(std::to_string(hrs) + ":" + std::to_string(mins) + ":" + std::to_string(secs));
}

Time Time::operator/(int divisor) const
{
    int totalSec = (hours * SEC_IN_HOUR + minutes * SEC_IN_MIN + seconds) / divisor;
    int hrs = totalSec / SEC_IN_HOUR;
    int mins = (totalSec % SEC_IN_HOUR) / SEC_IN_MIN;
    int secs = totalSec % SEC_IN_MIN;
    return Time(std::to_string(hrs) + ":" + std::to_string(mins) + ":" + std::to_string(secs));
}

Time Time::operator-(const Time &t) const
{
    int totalSec = (hours - t.hours) * SEC_IN_HOUR + (minutes - t.minutes) * SEC_IN_MIN + (seconds - t.seconds);
    int hrs = totalSec / SEC_IN_HOUR;
    int mins = (totalSec % SEC_IN_HOUR) / SEC_IN_MIN;
    int secs = totalSec % SEC_IN_MIN;
    return Time(std::to_string(hrs) + ":" + std::to_string(mins) + ":" + std::to_string(secs));
}
