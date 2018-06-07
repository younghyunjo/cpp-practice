#include <iostream>

class vector {
    int sz;
    double* elem;
    int space

public:
    vector() : sz{0}, elem{nullptr}, space{0} {}
    explicit vector(int s) : sz{s}, elem{new double[s]}, space{s}
    {
        for (int i=0; i<sz; ++i)
            elem[i] = 0;
    }

    vector(const vector&);
    vector &operator=(const vector&);

    vector(vector&&);
    vector& operator=(vector&&);

    ~vector() {
        delete [ ]  elem;
    }

    double& operator[] (int n) {
        return elem[n];
    }

    int size() const {return sz};
    int capacity() const {return space};

    void resize(int new size);
    void push_back(double d);
    void reserve(int newalloc);
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}