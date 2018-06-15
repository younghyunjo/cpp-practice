#include <iostream>

template <typename T, int N>
struct array {
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;
    using size_type = unsigned int;

    T elems[N];

    iterator begin() {
        return elems;
    }
    const_iterator begin() const {
        return elems;
    }
    iterator end() {
        return elems + N;
    }

    size_type size() const;

    T& operator[ ] (int n) {
        return elems[n];
    }
    const T& operator[] (int n) const {
        return elems[n];
    }

    const T& at(int n) const;
    T& at(int n);

    T* data() {
        return elems;
    }

    T* data() {
        return elems;
    }

    const T* data() const {
        return elems;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}