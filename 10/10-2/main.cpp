#include <iostream>
#include <fstream>
#include <vector>

const static double not_a_reading = -7777;
const static int not_a_month = -1;

struct Reading {
    int day;
    int hour;
    double temperature;
};

struct Day {
    std::vector<double> hour {std::vector<double>(24, not_a_reading)};
};

struct Month {
    int month {not_a_month};
    std::vector<Day> day{32};
};

struct Year {
    int year;
    std::vector<Month> month{12};
};

int month_to_int(const std::string& mstring) {
    if (mstring == "jan")
        return 0;
    if (mstring == "feb")
        return 1;
    if (mstring == "mar")
        return 2;
    if (mstring == "apr")
        return 3;
    if (mstring == "may")
        return 4;
    if (mstring == "jun")
        return 5;
    if (mstring == "jul")
        return 6;
    if (mstring == "aug")
        return 7;
    if (mstring == "sep")
        return 8;
    if (mstring == "oct")
        return 9;
    if (mstring == "nov")
        return 10;
    if (mstring == "dec")
        return 11;
    return -1;
}

void end_of_loop(std::istream& is, char end, const std::string& err_msg) {
    if (is.fail()) {
        is.clear();
        char ch;
        if (is >> ch && ch == end) {
            return;
        }
        std::runtime_error((const std::runtime_error&)err_msg);
    }
}

std::istream& operator>>(std::istream& is, Reading& r) {
    char open_brace;
    if (is >> open_brace && open_brace != '(') {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    char close_brace;
    int d;
    int h;
    double t;

    is >> d >> h >> t >> close_brace;
    if (!is || close_brace != ')') {
        std::runtime_error("Errored ");
    }
    r.day = d;
    r.hour = h;
    r.temperature = t;

    return is;
}

std::istream& operator>>(std::istream& is, Month& m) {
    char open_brace = 0;
    if (is >> open_brace && open_brace != '{') {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    std::string month_marker;
    std::string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month")
        std::runtime_error("MONTH >> error");

    m.month = month_to_int(mm);

    int duplicates = 0;

    for (Reading r; is >> r;) {
        if (m.day[r.day].hour[r.hour] != not_a_reading)
            ++duplicates;
        m.day[r.day].hour[r.hour] = r.temperature;
    }

    end_of_loop(is, '}', "ERR MONTH");
    return is;
}

std::istream& operator>>(std::istream& is, Year& y) {
    char open_brace;
    is >> open_brace;
    if (open_brace != '{') {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    std::string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year") {
        std::runtime_error("ERR YEAR");
    }

    while (true) {
        Month m;
        if (!(is >> m))
            break;
        y.month[m.month] = m;
        y.year = yy;
    }
    end_of_loop(is, '}', "ERR END YEAR");

    return is;
}

std::ostream& operator<<(std::ostream& os, Month& m) {

    os << m.month << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, Year& y) {
    os << y.year << ' ' ;
    for (int i=0; i<12; i++) {
        if (y.month[i].month != not_a_month)
            os << y.month[i] << std::endl;
    }
//    return os;
}

int main() {
    std::ifstream isf {"in"};
    if (!isf) {
        std::runtime_error("file open failed");
    }

    isf.exceptions(isf.exceptions() | std::ios_base::badbit);

    std::vector<Year> ys;
    while (true) {
        Year y;
        if (!(isf >> y)) {
            break;
        }
        ys.push_back(y);
        std::cout << y ;
    }

    return 0;
}