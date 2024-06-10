#include "CTime.h"

CTime::CTime(std::string_view CTimeString)
{
    std::stringstream ss(CTimeString.data());
    char tokenDelimiter;
    ss >> _mHours >> tokenDelimiter >> _mMinutes >> tokenDelimiter >> _mSeconds;
}

CTime CTime::operator+(const CTime &t) const
{
    CTime result;
    result._mSeconds = this->_mSeconds + t._mSeconds;
    result._mMinutes = this->_mMinutes + t._mMinutes + result._mSeconds / SECONDS_IN_MINUTE;
    result._mHours = this->_mHours + t._mHours + result._mMinutes / SECONDS_IN_MINUTE;
    result._mMinutes %= SECONDS_IN_MINUTE;
    result._mSeconds %= SECONDS_IN_MINUTE;

    if (result._mHours > 24)
    {
        result._mHours -= 24;
    }
    if (result._mMinutes > SECONDS_IN_MINUTE)
    {
        result._mMinutes -= SECONDS_IN_MINUTE;
        result._mHours += 1;
    }
    if (result._mSeconds > SECONDS_IN_MINUTE)
    {
        result._mSeconds -= SECONDS_IN_MINUTE;
        result._mMinutes += 1;
    }

    return result;
}

CTime CTime::operator/(const int t) const
{
    int TotalSeconds = this->_mHours * SECONDS_IN_HOUR + this->_mMinutes * SECONDS_IN_MINUTE + this->_mSeconds;
    TotalSeconds /= t;
    CTime result;
    result._mHours = TotalSeconds / SECONDS_IN_HOUR;
    result._mMinutes = (TotalSeconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
    result._mSeconds = TotalSeconds % SECONDS_IN_MINUTE;
    return result;
}
