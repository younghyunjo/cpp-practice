#include <iostream>

int main() {
    double v = 1234567.89;
    std::cout << std::defaultfloat << v<< "\t\t(General)\n"
              << std::fixed << v << "\t(Fixed)\n"
              << std::scientific << v<< "\t(Scientific\n";
    return 0;
}