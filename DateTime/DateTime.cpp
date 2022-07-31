#include "DateTime.h"

void DateTime::ConvertToString()
{
    char buf[30] = "";
    ::sprintf_s(buf, "%04d-%02d-%02d %02d:%02d:%02d", m_year, m_month, m_monthDay,
        m_hour, m_minute, m_second);
    m_dateTimeString = buf;
}

DateTime::DateTime(long long time)
{
    SetTime(time);
}

DateTime::operator time_t()
{
    return m_time;
}

DateTime& DateTime::operator=(long long time)
{
    SetTime(time);
    return *this;
}

bool DateTime::operator==(time_t time)
{
    return m_time == time;
}

bool DateTime::operator==(DateTime time)
{
    return m_time == time;
}

bool DateTime::operator!=(time_t time)
{
    return m_time != time;
}

bool DateTime::operator!=(DateTime time)
{
    return m_time != time;
}

bool DateTime::operator>(time_t time)
{
    return m_time > time;
}

bool DateTime::operator>(DateTime time)
{
    return m_time > time;
}

bool DateTime::operator>=(time_t time)
{
    return m_time >= time;
}

bool DateTime::operator>=(DateTime time)
{
    return m_time >= time;
}

bool DateTime::operator<(time_t time)
{
    return m_time < time;
}

bool DateTime::operator<(DateTime time)
{
    return m_time < time;
}

bool DateTime::operator<=(time_t time)
{
    return m_time <= time;
}

bool DateTime::operator<=(DateTime time)
{
    return m_time <= time;
}

DateTime::DateTime(unsigned short year, unsigned char month, unsigned char monthDay, unsigned char hour, unsigned char minute, unsigned char second)
{
    SetDateTime(year, month, monthDay, hour, minute, second);
}

void DateTime::SetTime(long long time)
{
    m_time = time;

    tm T;
    errno_t err_no = _localtime64_s(&T, &m_time);

    m_year = static_cast<unsigned short>(T.tm_year + 1900);
    m_month = static_cast<unsigned char>(T.tm_mon + 1);
    m_monthDay = static_cast<unsigned char>(T.tm_mday);
    m_hour = static_cast<unsigned char>(T.tm_hour);
    m_minute = static_cast<unsigned char>(T.tm_min);
    m_second = static_cast<unsigned char>(T.tm_sec);
    m_weekDay = (T.tm_wday == 0) ? 7 : static_cast<unsigned char>(T.tm_wday);

    ConvertToString();
}

void DateTime::SetDateTime(unsigned short year, unsigned char month, unsigned char monthDay, unsigned char hour, unsigned char minute, unsigned char second)
{
    tm T;
    T.tm_year = static_cast<int>(year - 1900);
    T.tm_mon = static_cast<int>(month - 1);
    T.tm_mday = static_cast<int>(monthDay);
    T.tm_hour = static_cast<int>(hour);
    T.tm_min = static_cast<int>(minute);
    T.tm_sec = static_cast<int>(second);
    T.tm_isdst = 0;

    time_t t = mktime(&T);
    if (t < 0)
        t = 0;

    SetTime(t);
}

std::string DateTime::ToString()
{
    return m_dateTimeString;
}
