#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
template <typename T>
class LinkedList{
    T *data;
    LinkedList *next;
    static int size;
    int position;

public:
    LinkedList();
    LinkedList(T);
    ~LinkedList();
    void add(T);
    template<typename T1, typename ...T2>
    void add(T1, T2 ...);
    void addAtPosition(int, T);
    void removeFirst();
    void removeLast();
    template<typename T1>
    void remove(T1);
    void print();
    void clear();
};

#include "linkedlist.inl"
#endif /* LINKED_LIST_HPP */