#pragma once

#include <iostream>
#include <string>
#include <sstream>

class CTime
{
public:
    static constexpr auto SECONDS_IN_HOUR = 3600;
    static constexpr auto SECONDS_IN_MINUTE = 60;

    CTime() = default;
    explicit CTime(std::string_view CTimeString);
    ~CTime() = default;

    CTime &operator=(const CTime &time) = default;
    auto operator<=>(const CTime &t) const = default;

    inline int GetMinute() const { return _mMinutes; };
    inline int GetSecond() const { return _mSeconds; };
    inline int GetHour() const { return _mHours; };

    inline void SetMinutes(const int min) { _mMinutes = min; };
    inline void SetSeconds(const int sec) { _mSeconds = sec; };
    inline void SetHours(const int hur) { _mHours = hur; };

    CTime operator+(const CTime &t) const;
    CTime operator/(const int t) const;

    friend std::ostream &operator<<(std::ostream &o, const CTime &t)
    {
        o << t.GetHour() << ":" << t.GetMinute() << ":" << t.GetSecond() << " ";
        return o;
    }

private:
    int _mHours = 0;
    int _mMinutes = 0;
    int _mSeconds = 0;
};