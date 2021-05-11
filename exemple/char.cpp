#include "../linkedlist.hpp"



int main()
{
    LinkedList<char> ll;
    ll.add('a','b','c','d','e');
    ll.print();
    ll.removeFirst();
    ll.print();
    ll.removeLast();
    ll.print();
    ll.remove('c');
    ll.print();
    ll.clear();
}