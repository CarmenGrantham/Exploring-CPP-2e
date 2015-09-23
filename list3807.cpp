//
// Created by carmen on 23/09/2015.
//
#include <iostream>
#include <string>
class work {
public:
    work() = default;
    work(work const&) = default;
    work(std::string const& id, std::string const& title) : id_{id}, title_{title} {}
    virtual ~work() {}
    std::string const& id()     const {return id_; }
    std::string const& title()  const {return title_; }
    virtual void print(std::ostream&) const=0;              // Don't include parameter name or names, compiler only needs type

private:
    std::string id_;
    std::string title_;
};

class book : public work {
public:
    book() : work{}, author_{}, pubyear_{} {}
    book(book const&) = default;
    book(std::string const& id, std::string const& title, std::string const& author, int pubyear) :
            work{id, title}, author_{author}, pubyear_{pubyear} {}
    std::string     const& author() const { return author_; }
    int pubyear()   const { return pubyear_; }
    void print(std::ostream& out) const override {
        out << author() << ", " << title() << ", " << pubyear() << ".";
    }
private:
    std::string author_;
    int pubyear_; ///< year of publication
};

class periodical : public work {
public:
    periodical() : work{}, volume_{0}, number_{0}, date_{} {}
    periodical(periodical const&) = default;
    periodical(std::string const& id, std::string const& title, int volume, int number, std::string const& date) :
            work{id, title}, volume_{volume}, number_{number}, date_{date}{}
    int volume()    const {return volume_; }
    int number()    const { return number_; }
    std::string     const& date() const { return date_; }
    void print(std::ostream& out) const override {
        out << title() << ", " << volume() << "(" << number() << "), " << date() << ".";
    }
private:
    int volume_;        ///< volume number
    int number_;        ///< issue number
    std::string date_;  ///< publication date
};

std::ostream& operator<<(std::ostream& out, work const& w) {
    w.print(out);
    return out;
}

class movie : public work {
public:
    movie() : work{}, runtime_{0} {}
    movie(movie const&) = default;
    movie(std::string const& id, std::string const& title, int runtime) : work{id, title}, runtime_{runtime} {};
    int runtime() const { return runtime_; }
    void print(std::ostream& out) const override {
        out << title() << " (" << runtime() << " minutes).";
    }

private:
    int runtime_;
};

int main() {
    book sc {"1", "The Sun Also Crashes", "Earnest Hemmingway", 2000};
    book ecpp {"2", "Exploring C++", "Ray Lischner", 2013};
    periodical pop {"3", "Popular C++", 13, 42, "January 1, 2000"};
    periodical today {"4", "C++ Today", 1, 1, "January 13, 1984"};
    movie tr {"5", "Lord of the Token Rings", 314};

    std::cout << sc << "\n";
    std::cout << ecpp << "\n";
    std::cout << pop << "\n";
    std::cout << today << "\n";
    std::cout << tr << "\n";
}