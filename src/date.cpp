//need more work to read date value from Excel

#include "date.h"
#include <ctime>

#define is_leap(Y) (((Y)&3)==0&&((Y)%25!=0||((Y)&15)==0))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

date::date (const Csv::multitype& _year, const Csv::multitype& _month, const Csv::multitype& _day)
{
    year = _year.to_int();
    month = Max(1, Min(12, _month.to_int()));
    if (month == 4 || month == 6 || month == 9 || month == 11)
        day = Max(1, Min(30, _day.to_int()));
    else
    if (month == 2)
        day = Max(1, Min(28 + is_leap(year), _day.to_int()));
    else
        day = Max(1, Min(31, _day.to_int()));
}

date& date::today()
{
    std::time_t t = std::time(0);
    std::tm *cur = std::localtime(&t);
    year = cur->tm_year + 1900;
    month = cur->tm_mon + 1;
    day = cur->tm_mday;
    return *this;
}

date& date::string_to_time (const Csv::multitype& e)    //format will be MM/DD/YYYY
{
    year = month = day = 1;
    char *_e = e.to_str();
    int Ne = strlen(_e);
    int year_len = 4;
    int mon_len = 2;
    int day_len = 2;
    if (Ne != 10)
        return *this;
    
    //convert month
    Csv::multitype __month = _e[0];
    __month = __month.append(_e[1]);
    month = __month.to_int(); 

    //convert day
    Csv::multitype __day = _e[3];
    __day = __day.append(_e[4]);
    day = __day.to_int();

    //convert year
    Csv::multitype __year = _e[6];
    for (int y = 7; y < 10; ++y)
    {
        __year = __year.append(_e[y]);
    }
    year = __year.to_int();
    return *this;
}

Csv::multitype date::time_to_string () const
{
    char format[11] = "MM/DD/YYYY";
    char* s = format;
    int Ns = strlen(s);
    for (int i = 0; i < Ns / 2; ++i)
    {
        char tmp = s[i];
        s[i] = s[Ns - 1 - i];
        s[Ns - 1 - i] = tmp;
    }
    for (int i = 0; i < Ns; ++i)
    {
        if (s[i] == 'Y')
        {
            int _year = year;
            s[i] = char(_year % 10 + '0');
            _year /= 10;
            while (i + 1 < Ns && s[i + 1] == 'Y')
            {
                s[++i] = char(_year % 10 + '0');
                _year /= 10;
            }
        }
        if (s[i] == 'M')
        {
            int _month = month;
            s[i] = char(_month % 10 + '0');
            _month /= 10;
            while (i + 1 < Ns && s[i + 1] == 'M')
            {
                s[++i] = char(_month % 10 + '0');
                _month /= 10;
            }
        }
        if (s[i] == 'D')
        {
            int _day = day;
            s[i] = char(_day % 10 + '0');
            _day /= 10;
            while (i + 1 < Ns && s[i + 1] == 'D')
            {
                s[++i] = char(_day % 10 + '0');
                _day /= 10;
            }
        }
        return Csv::multitype(s);
    }
}


bool date::operator< (const date& d) const
{
    return year != d.year ? (year < d.year) : (month != d.month ? (month < d.month) : (day < d.day));
    // compare year then month then day
}

bool date::operator> (const date& d) const
{
    return year != d.year ? (year > d.year) : (month != d.month ? (month > d.month) : (day > d.day));
    // compare year then month then day
}

