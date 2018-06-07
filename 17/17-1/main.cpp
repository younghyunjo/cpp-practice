#include <iostream>

class vector {
public:
    vector(int s) : sz{s}, elem(new double [s]) {

    }
    ~vector() {delete [ ] elem; }

    int size() const {
        return sz;
    }

    double get(int n) const {
        return elem[n];
    }
    void set (int n, double v) {
        elem[n] = v;
    }

private:
    int sz;
    double* elem;
};

int main() {
    vector v(5);
    v.set(0, 0.0);
    v.set(1, 1.1);
    v.set(2, 2.2);
    v.set(3, 3.3);
    v.set(4, 4.4);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}