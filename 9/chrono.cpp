//
// Created by younghyun on 18. 6. 2.
//

#include <iostream>
#include "chrono.h"

namespace Chrono {

    bool is_date(int y, Month m, int d);

Date::Date(int yy, Month mm, int dd)
        : y{yy}, m{mm}, d{dd}
{
    if (!is_date(yy, mm, dd))
        throw Invalid();
}

const Date& default_date()
{
    static Date dd {2001, Month::jan, 1};
    return dd;
}

Date::Date()
        :y{default_date().year()},
         m{default_date().month()},
         d{default_date().day()}
{
}

void Date::add_day(int n)
{
    //
}

void Date::add_month(int n)
{
    //
}

void Date::add_year(int n)
{
    //
}

bool leapyear(int y)
{
    return false;
}

bool is_date(int y, Month m, int d) {
    if (d <= 0)
        return false;
    if (m < Month::jan || Month::dec < m)
        return false;

    int days_in_month = 31;

    switch (m) {
    case Month::feb:
        days_in_month = leapyear(y) ? 29 : 28;
        break;
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
        days_in_month = 30;
        break;
    }

    if (days_in_month < d)
        return false;
    return true;
}

bool operator==(const Date& a, const Date& b) {
    return a.year() == b.year() &&
           a.month() == b.month() &&
           a.day() == b.day();
}

bool operator!=(const Date& a, const Date& b) {
    return !(a==b);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    return os << ')' << d.year();
//             << '.' << d.month()
//             << '.' << d.day() << ')';
}

std::istream& operator>>(std::istream& is, Date& dd) {
    int y, m, d;
    char ch1, ch2, ch3, ch4;

    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;

    if (!is)
        return is;

    if (ch1 !='(' || ch2 != ',' || ch3 != ',' || ch4!=')') {
        is.clear(std::ios_base::failbit);
        return is;
    }

    dd = Date(y, Month(m), d);
    return is;
}

enum class Day {
    sunday, monday, tuesday, wednesday, thurday, friday, saturday
};

Day day_of_week(const Date& d) {

}

Day next_Sunday(const Date& d) {

}
Day next_weekday(const Date& d) {

}


}  //namespace Chrono
