#pragma once
#include <corecrt_wtime.h>
#include <time.h>
#include <string>

class DateTime
{
private:
    time_t m_time = 0;
    unsigned short m_year = 0;
    unsigned char m_month = 0;
    unsigned char m_monthDay = 0;
    unsigned char m_hour = 0;
    unsigned char m_minute = 0;
    unsigned char m_second = 0;
    unsigned char m_weekDay = 1;
    std::string m_dateTimeString;
    void ConvertToString();
public:
    DateTime() { SetTime(0); }
    ~DateTime() {}
    DateTime(long long time);
    operator time_t();
    DateTime& operator=(long long time);
    bool operator==(time_t time);
    bool operator==(DateTime time);
    bool operator!=(time_t time);
    bool operator!=(DateTime time);
    bool operator>(time_t time);
    bool operator>(DateTime time);
    bool operator>=(time_t time);
    bool operator>=(DateTime time);
    bool operator<(time_t time);
    bool operator<(DateTime time);
    bool operator<=(time_t time);
    bool operator<=(DateTime time);

    DateTime(unsigned short year, unsigned char month, unsigned char monthDay,
        unsigned char hour, unsigned char minute, unsigned char second);
    void SetTime(long long time);
    void SetDateTime(unsigned short year, unsigned char month, unsigned char monthDay,
        unsigned char hour, unsigned char minute, unsigned char second);
    std::string ToString();
};

