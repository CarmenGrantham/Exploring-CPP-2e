//
// Created by carmen on 30/09/2015.
//

// Content of std::pair class template
template<class T, class U>
struct pair {
    typedef T first_type;
    typedef T second_type;
    T first;
    U second;
    pair();
    pair(T const& first, U const& second);

    template<class T2, class U2>
    pair(pair<T2, U2> const& other);
};

// Specialising pair to hand 2 void parameters
template<>
struct pair<void, void> {
    typedef void first_type;
    typedef void second_type;
    pair(pair const&) = default;
    pair() = default;
    pair& operator=(pair const&) = default;
};

// Specialising pair for one void argument
template<class U>
struct pair<void, U> {
    typedef void first_type;
    typedef U second_type;
    U second;
    pair() = default;
    pair(pair const&) = default;
    pair(U const& second);
    template<class U2>
    pair(pair<void, U2>, const& other);
};

// Specialising pair for other void argument
template<class T>
struct pair<T, void> {
    typedef T first_type;
    typedef void second_type;
    T first;
    pair() = default;
    pair(pair const&) = default;
    pair(T const& first);
    template<class T2>
    pair(pair<T2, void> const& other);
};
