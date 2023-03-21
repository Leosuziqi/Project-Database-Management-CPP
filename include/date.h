#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "csv.h"

// date structure with some useful functions.
struct date
{
    int year, month, day;

    // constructor.
    date (const Csv::multitype& _year = 1,
          const Csv::multitype& _month = 1,
          const Csv::multitype& _day = 1);

    // set date to today.
    date& today();

    // parse string into time.
    // Format is restricted as MM/DD/YYYY.
    date& string_to_time (const Csv::multitype& e);

    // compile date to string.
    // Format is restricted as MM/DD/YYYY.
    Csv::multitype time_to_string () const;

    // compare operators.
    bool operator<  (const date& d) const;
    bool operator>  (const date& d) const;

    void display_date() {
        std::cout << year;
        std::cout << month;
        std::cout << day;
    }
};

#endif // DATE_H
