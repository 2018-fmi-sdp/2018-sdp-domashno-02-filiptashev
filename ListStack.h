#pragma once

/**
 * @file TODO - какви класове и функции дефинира този файл
 */

#include <cassert>
#include <typeinfo>
#include <ostream>

// Forward declarations necessary for friend template operator <<
template <class T>
class ListStack;

template <class T>
std::ostream& operator<<(std::ostream& o, const ListStack<T>& stack);

template<class T>
struct TNode {
    T data;
    TNode* next;
};

/*
    To see how this class is used see the ListStack_test.cpp
    To run only ListStack tests:
        build/rpn-tests "[ListStack]"
    To see a list of all test checks:
        build/rpn-tests "[ListStack]" --reporter=compact --succes
*/
template<class T>
class ListStack {
public:
    ListStack();
    ListStack(const ListStack<T>& other);
    ~ListStack();
    ListStack& operator=(const ListStack<T>& other);

    // Helper method. Returns true if _size and _top are consistent
    bool isConsistent() const;
    bool isEmpty() const;
    unsigned size() const;
    T top() const;
    bool pop();
    void push(const T& value);

    bool operator==(const ListStack<T>& other) const;
    bool operator!=(const ListStack<T>& other) const;

    friend std::ostream& operator<< <T>(std::ostream& o, const ListStack<T>& stack);
private:
    void copyFrom(const ListStack<T>& other);
    void deleteThis();

    TNode<T>* _top;
    unsigned _size;
};

template <class T>
inline ListStack<T>::ListStack() :_top(nullptr), _size(0)
{
}

template <class T>
inline ListStack<T>::ListStack(const ListStack<T>& other)
    :_top(nullptr), _size(0)
{
    copyFrom(other);
}

template <class T>
inline ListStack<T>::~ListStack()
{
    deleteThis();
}

template <class T>
inline ListStack<T>& ListStack<T>::operator=(const ListStack<T>& other)
{
    if (this == &other)
        return *this;

    deleteThis();
    copyFrom(other);
    return *this;
}

template <class T>
inline bool ListStack<T>::isConsistent() const
{
    return (_size == 0 && _top == nullptr) || (_size != 0 && _top != nullptr);
}

template <class T>
inline bool ListStack<T>::isEmpty() const
{
    return _size == 0;
}

template <class T>
inline unsigned ListStack<T>::size() const
{
    return _size;
}

template <class T>
inline T ListStack<T>::top() const
{
    assert(!isEmpty());
    T result; // = TODO - the value of the node at the beginning of the list
    return result;
}

template <class T>
inline bool ListStack<T>::pop()
{
    if (isEmpty())
        return false;

    // TODO - remove the node at the beginning of the linked list
    --_size;
    return true;
}

template <class T>
inline void ListStack<T>::push(const T& value)
{
    TNode<T>* tmp = new TNode<T>;
    // TODO - add value in tmp node and place it in the
    //      begining of the linked list
    ++_size;
}

template <class T>
inline bool ListStack<T>::operator==(const ListStack<T>& other) const
{
    if (size() != other.size())
        return false;

    TNode<T>* ourNode = _top;
    TNode<T>* otherNode = other._top;
    while(ourNode) {
        if (ourNode->data != otherNode->data)
            return false;
        ourNode = ourNode->next;
        otherNode = otherNode->next;
    }
    return true;
}


template <class T>
inline bool ListStack<T>::operator!=(const ListStack<T>& other) const
{
    // Call operator == from above
    return !(*this == other);
}


template <class T>
inline void ListStack<T>::copyFrom(const ListStack& other)
{
    // Check that we call copyFrom only when this does not take any dynamic memory
    assert(isEmpty());
    if (other.isEmpty())
        return;

    // This is a standard copy from one linked list to another
    TNode<T>* otherNode = other._top;
    _top = new TNode<T>;
    _top->data = otherNode->data;
    _top->next = nullptr;
    ++_size;

    otherNode = otherNode->next;
    TNode<T>* ourLastNode = _top;

    // In each iteration we create a new node after ourLastNode and copy otherNode in it
    while(otherNode) {
        ourLastNode->next = new TNode<T>;
        ourLastNode = ourLastNode->next;
        ourLastNode->data = otherNode->data;
        ourLastNode->next = nullptr;
        ++_size;
        otherNode = otherNode->next;
    }

    assert(size() == other.size());
}

template <class T>
inline void ListStack<T>::deleteThis()
{
    while(pop());
}

template<class T>
std::ostream& operator<<(std::ostream& o, const ListStack<T>& stack)
{
    o << "ListStack<" << typeid(T).name() << ">(size=" << stack._size << ", values={";

    if(!stack._top) {
        o << "})";
        return o;
    }

    TNode<T>* node = stack._top;
    while(node->next) {
        o << node->data << ", ";
        node = node->next;
    }
    o << node->data << "})";
    return o;
}