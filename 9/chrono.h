//
// Created by younghyun on 18. 6. 2.
//

#ifndef INC_9_CHRONO_H
#define INC_9_CHRONO_H
namespace Chrono {

enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
    class Invalid {};
    Date(int y, Month m, int d);
    Date();

    int day() const {return d;}
    Month month() const {return m;}
    int year() const { return y;}

    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

private:
    int y;
    Month m;
    int d;
};

} //namespace Chrono

#endif //INC_9_CHRONO_H
