//
// Created by carmen on 2/10/2015.
//
#include <algorithm>
#include <iostream>
#include <iterator>             // Compiler throws exception as it can't find operator>> for token parameter
#include <string>
#include <vector>

namespace parser {
    class token {
    public:
        token() : text_{}{}
        token(std::string& s) : text_{s} {}
        token& operator=(std::string const& s) { text_ = s; return *this;}
        std::string text() const { return text_; }

    private:
        std::string text_;
    };

    std::istream& operator>>(std::istream& in, parser::token& tok) {
        std::string str{};
        if (in >> str) {
            tok = str;
        }
        return in;
    }

    std::ostream& operator<<(std::ostream& out, parser::token const& tok) {
        out << tok.text();
        return out;
    }
}


int main() {
    using namespace parser;
    using namespace std;

    vector<token> tokens{};
    // Getting input from user doesn't work in CLion, so add it by hand
    //copy(istream_iterator<token>(std::cin), istream_iterator<token>(), back_inserter(tokens));


    std::string s1 {"100"};
    std::string s2 {"abc"};
    token t1 (s1);
    token t2 {s2};
    tokens.push_back(token());
    tokens.push_back(t1);
    tokens.push_back(t2);

    copy(tokens.begin(), tokens.end(), ostream_iterator<token>(cout, "\n"));
}
