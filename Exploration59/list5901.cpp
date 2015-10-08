//
// Created by carmen on 8/10/2015.
//

#include <cstdlib>

template<class T>
class list {
public:
    list() : head_{nullptr}, tail_{nullptr}, size_{0} {};
    ~list() { clear(); }
    void clear();               ///< Erase all nodes in the list. Reset size to 0.
    void push_back(T const& x); ///< Add to tail.
    void pop_back();            ///< Erase from tail.
    // Other useful functions.

private:
    class node {
    public:
        node(T const& key) : next_{nullptr}, prev_{nullptr}, value_{key} {}
        node* next_;
        node* prev_;
        T value_;
    };

    node* head_;        ///< Start of the list
    node* tail_;        ///< End of the list
    std::size_t size_;  ///< Number of nodes in the list
};

template<class T>
void list<T>::push_back(T const &x) {
    node* n{new node{x}};
    if (tail_ == nullptr) {
        head_ = tail_ = n;
    } else {
        n->prev_ = tail_;
        tail_->next_ = n;
    }
    ++size_;
}

template<class T>
void list<T>::pop_back() {
    node* n{tail_};
    if (head_ == tail_) {
        head_ = tail_ = nullptr;
    } else {
        tail_ = tail_->prev_;
        tail_->next_ = nullptr;
    }
    --size_;
    delete n;
}