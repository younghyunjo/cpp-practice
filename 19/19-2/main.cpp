#include <iostream>

template<typename T>
class vector {
    int sz;
    T* elem;
    int space;

public:
    vector() : sz{0}, elem{nullptr}, space{0} {
    }
    explicit vector(int s) :sz {s}, elem{new T[s]}, space{s} {
        for (int i=0; i<sz; i++)
            elem[i] = 0;
    }

    vector(const vector&);
    vector& operator=(const vector&);

    vector(vector&&);
    vector& operator=(vector&&);

    ~vector() {delete [ ]  elem};

    T& operator[ ] (int n) {
        return elem[n];
    }
    const T& operator[ ] (int n) const {
        return elem[n];
    }

    int size() const {
        return size;
    }
    int capacity() const {
        return space;
    }

    void resize(int newsize);
    void push_back(const T& d);
    void reserve(int newalloc);=
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}