#pragma once

#include <iostream>
#include <string>
#include <sstream>

class Time
{
public:
    static constexpr auto SEC_IN_HOUR = 3600;
    static constexpr auto SEC_IN_MIN = 60;

    Time() = default;
    explicit Time(std::string_view timeString);
    ~Time() = default;

    Time &operator=(const Time &time) = default;
    auto operator<=>(const Time &t) const = default;

    int GetMin() const { return _min; };
    int GetSec() const { return _sec; };
    int GetHour() const { return _hours; };

    void SetMin(const int min) { _min = min; };
    void SetSec(const int sec) { _sec = sec; };
    void SetHours(const int hur) { _hours = hur; };

    Time operator+(const Time &t) const;
    Time operator/(const int t) const;
    Time operator-(const Time &t) const;

    friend std::ostream &operator<<(std::ostream &o, const Time &t)
    {
        o << t.GetHour() << ":" << t.GetMin() << ":" << t.GetSec() << " ";
        return o;
    }

private:
    int _hours = 0;
    int _min = 0;
    int _sec = 0;
};