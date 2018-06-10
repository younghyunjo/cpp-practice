#include <iostream>
#include <vector>
#include <list>

using namespace std;

using Line = vector<char>;

class Text_iterator {
    list<Line>::iterator ln;
    Line::iterator pos;

public:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
            : ln{ll}, pos{pp} {}
    char& operator*() {
        return *pos;
    }
    Text_iterator& operator++()
    bool opeator==(const Text_iterator& other) const {
        return ln == other.ln && pos == other.pos;
    }
    bool operator !=(const Text_iterator& other) const {}
    return !(*this == other);
};


struct Document {
    list<Line> line;
    Document() {
        line.push_back(Line{});
    }

    Text_iterator begin() {
        return Text_iterator(line.begin(), (*line.begin()).begin());
    }
    Text_iterator end() {
        auto last = line.end();
        --last;
        return Text_iterator(last, (*last).end());
    }
};

istream& operator>>(istream& is, Document& d) {
    for (char ch; is.get(ch);) {
        d.line.back().push_back(ch);
        if (ch == '\n')
            d.line.push_back(Line{});
    }
    if (d.line.back().size())
        d.line.push_back(Line{});
    return is;
}


Text_iterator& Text_iterator::operator++() {
    ++pos;
    if (pos == (*ln).end()) {
        ++ln;
        pos = (*ln).begin();
    }
    return *this;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}