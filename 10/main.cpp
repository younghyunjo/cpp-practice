
#include <iostream>
#include <fstream>
#include <vector>

inline void error(const std::string& s) {
    throw std::runtime_error(s);
}

struct Reading {
    int hour;
    double temperature;
};

int main() {
    std::cout << "input file name:";
    std::string iname;
    std::cin >> iname;
    std::ifstream ist {iname};
    if (!ist) {
        error("Can't open file" + iname);
    }

    std::cout<< "output file name:";
    std::string oname;
    std::cin >> oname;
    std::ofstream ost {oname};
    if (!ost) {
        error("Can`t open file" + oname);
    }

    std::vector<Reading> temps;
    int hour;
    double temperature;

    while (ist >> hour >> temperature) {
        if (hour < 0 || hour > 23) {
            error("Invalid hour");
        }
        temps.push_back(Reading{hour, temperature});
    }

    for (int i=0; i<temps.size(); i++) {
        ost << '(' << temps[i].hour << ','
            << temps[i].temperature << ")\n";
    }

    return 0;
}