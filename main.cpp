#include "linkedlist.hpp"



int main()
{
    LinkedList<int> ll;
    ll.add(1,2,3,4,5);
    ll.print();
    ll.removeFirst();
    ll.print();
    ll.removeLast();
    ll.print();
    ll.remove(3);
    ll.print();
    ll.clear();
    ll.print();
}