#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Punct_stream {
public:
    Punct_stream(std::istream& is)
            : source{is}, sensitive{true} { }
    void whitespace(const std::string& s) {
        white = s;
    }
    void add_white(char c) {
        white += c;
    }
    bool is_whitespace(char c) {
        for (char w : white) {
            if (c == w)
                return true;
        }
        return false;
    }

    void case_sensitive(bool b) {
        sensitive = b;
    }
    bool is_case_sensitive() {
        return sensitive;
    }

    Punct_stream& operator>>(std::string& s) {
        while (!(buffer >> s)) {
            if (buffer.bad() || !source.good())
                return *this;
            buffer.clear();

            std::string line;
            std::getline(source, line);

            for (char& ch : line) {
                if (is_whitespace(ch)) {
                    ch = ' ';
                }
                else if (sensitive) {
                    tolower(ch);
                }
            }

            buffer.str(line);
        }

        return *this;
    }

    operator bool() {
        return !(source.fail() || source.bad()) && source.good();
    }

private:
    std::istream& source;
    std::istringstream buffer;
    std::string white;
    bool sensitive;
};


int main() {
    Punct_stream ps {std::cin};
    ps.whitespace(";:,.?!");
    ps.case_sensitive(false);

    std::cout << "Enter Sentence\n";
    std::vector<std::string> vs;
    for (std::string word; ps >> word;) {
        std::cout << word << "\n";
        vs.push_back(word);
    }
}