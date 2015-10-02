//
// Created by carmen on 2/10/2015.
//
#include <algorithm>
#include <iostream>
#include <iterator>             // Compiler throws exception as it can't find operator>> for token parameter
#include <string>
#include <map>

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

    bool operator<(token const& a, token const& b) {
        return a.text() < b.text();
    }

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

    std::ostream& operator<<(std::ostream& out, std::pair<const token, long> const& count) {
        out << count.first.text() << '\t' << count.second << '\n';
        return out;
    }
}


int main() {
    using namespace parser;
    using namespace std;

    map<token, long> tokens{};
    // Getting input from user doesn't work in CLion, so add it by hand
    //token tok{};
    //while(std::cin >> tok) {
    //    ++tokens[tok];
    //}

    std::string s1 {"100"};
    std::string s2 {"abc"};
    token t1 (s1);
    token t2 {s2};
    ++tokens[token()];
    ++tokens[t1];
    ++tokens[t2];
    ++tokens[t2];

    copy(tokens.begin(), tokens.end(), ostream_iterator<pair<const token, long> >(cout));
}
