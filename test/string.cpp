#include "../linkedlist.hpp"
#include <string>
#include <iostream>

class String :public std::string{
public:
    std::string str;

    String(std::string _str)
        :str(_str){}

    String(const char* _str)
        :str(_str){}
    
    String()
        :str(nullptr){}

    bool operator==(std::string other)
    {
        if(this->str.compare(other))
            return false;
        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, String self);
};

std::ostream& operator<<(std::ostream& os, String self)
{
    os << self.str;
    return os;
}

int main()
{
    LinkedList<String> ll;
    ll.add("One", "Two", "Three", "Four", "Five");
    ll.print();
    ll.removeFirst();
    ll.print();
    ll.removeLast();
    ll.print();
    ll.remove("Three");
    ll.print();
    ll.clear();
}
