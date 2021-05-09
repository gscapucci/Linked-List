#include "linkedlist.hpp"

template<typename T>
int LinkedList<T>::size = 0;

template<typename T>
LinkedList<T>::LinkedList() 
    :data(nullptr), next(nullptr),position(0){size++;}

template<typename T>
LinkedList<T>::LinkedList(T newData)
{
    this->data = new T(newData);
    this->next = nullptr;
    size++;
}

template<typename T>
LinkedList<T>::~LinkedList(){delete data;}

template<typename T>
void LinkedList<T>::add(T newData)
{
    static int pos = -1;
    pos++;
    if(this->data == nullptr)
    {
        this->data = new T(newData);
        this->position = pos;
        pos = 0;
        return;
    }
    else if(this->next == nullptr)
    {
        this->next = new LinkedList(newData);
        this->next->position = pos;
        pos = 0;
        return;
    }
    else
        this->next->add(newData);
}

template<typename T> 
template<typename T1, typename ...T2>
void LinkedList<T>::add(T1 first, T2 ...datas)
{
    this->add((T)first);
    return add((T)datas...);
}

template<typename T>
void LinkedList<T>::addAtPosition(int pos, T data)
{
    if(this->position == pos)
    {
        LinkedList<T> *tmp = new LinkedList(*(this->data));
        tmp->next = this->next;
        this->next = tmp;
        *(this->data) = data;
        return;
    }
    if(this->next == nullptr)
        return;
    if(this->next->position == pos)
    {
        LinkedList<T> *tmp, *newNode;
        tmp = this->next;
        this->next = new LinkedList(data);
        this->next->next = tmp;
        return;
    }
    this->next->addAtPosition(pos, data);
}

template<typename T>
void LinkedList<T>::removeFirst()
{
    LinkedList<T> *tmp = this->next;
    if(this->next != nullptr)
    {
        *(this->data) = *(tmp->data);
        this->next = tmp->next;
        delete tmp;
        return;
    }
    delete data;
}

template<typename T>
void LinkedList<T>::removeLast()
{
    if(this->next == nullptr)
    {
        this->removeFirst();
    }
    if(this->next->next != nullptr)
    {
        this->next->removeLast();
        return;
    }
    LinkedList<T> *tmp = this->next;
    this->next = nullptr;
    delete tmp;
}

template<typename T>
template<typename T1>
void LinkedList<T>::remove(T1 data)
{

    if(*(this->data) == data)
    {
        this->removeFirst();
        return;
    }
    if(this->next == nullptr)
    {
        std::cout << "\"" << data << "\"" << " not found." << std::endl;
        return;
    }
    if(*(this->next->data) == data)
    {
        LinkedList<T> *tmp = this->next;
        this->next = this->next->next;
        delete tmp;
        return;
    }
    this->next->remove(data);
    return;
}

template<typename T>
void LinkedList<T>::print()
{
    if(this->data == nullptr)
    {
        std::cout << "List in empty." << std::endl;
        return;
    }
    std::cout << *(this->data) << "->";
    if(this->next != nullptr)
        this->next->print();
    else
        std::cout << "nullptr" << std::endl;
}

template<typename T>
void LinkedList<T>::clear()
{
    if(this->next != nullptr)
        this->next->clear();
    delete data;
    delete this->next;
    data = nullptr;
    this->next = nullptr;
}