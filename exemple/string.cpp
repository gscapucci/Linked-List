#include "../linkedlist.hpp"
#include <string>
#include <iostream>
//
//You need to overload operators to work with classes
//
class String{
private:
    std::string str;
public:
    String(std::string _str)
        :str(_str){}

    String(const char* _str)
        :str(_str){}
    
    String()
        :str(nullptr){}

    bool operator==(std::string& other)
    {
        if(this->str.compare(other))
            return false;
        return true;
    }

    bool operator==(const char* other)
    {
        if(this->str.compare(other))
            return false;
        return true;
    }

    bool operator==(String& other)
    {
        if(this->str.compare(other.str))
            return false;
        return true;
    }

    void operator=(String& other)
    {
        this->str = other.str;
    }

    void operator=(std::string& other)
    {
        this->str = other;
    }

    void operator=(const char* other)
    {
        this->str = other;
    }


    std::string get()
    {
        return this->str;
    }
    friend std::ostream& operator<<(std::ostream& os, String self);
};

std::ostream& operator<<(std::ostream& os, String self)
{
    os << self.get();
    return os;
}




int main()
{
    LinkedList<String> ll;
    ll.add("One", "Two", "Three", "Four", "Five");
    ll.print();
    ll.reverse();
    ll.print();
    ll.removeFirst();
    ll.print();
    ll.removeLast();
    ll.print();
    ll.remove("Three");
    ll.print();
    ll.clear();
}