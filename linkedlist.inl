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
    T first1 = first;
    this->add((T)first1);
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
    if(this->data == nullptr)
        return;

    LinkedList<T> *tmp, *tmp2; 
    tmp = tmp2 = this->next;

    if(this->next != nullptr)
    {
        for(int i = 0;;i++)
        {
            tmp2->position = i;
            if(tmp2->next == nullptr)
                break;
            tmp2 = tmp2->next;
        }
        
        *(this->data) = *(tmp->data);
        this->next = tmp->next;
        delete tmp;
        this->size--;
        return;
    }
    delete this->data;
    this->size--;
}

template<typename T>
void LinkedList<T>::removeLast()
{
    if(this->data == nullptr)
        return;
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
    this->size--;
}

template<typename T>
template<typename T1>
void LinkedList<T>::remove(T1 data)
{
    if(this->data == nullptr)   
        return;
    T data1 = data;
    if(*(this->data) == data1)
    {
        this->removeFirst();
        return;
    }
    if(this->next == nullptr)
    {
        std::cout << "\"" << data1 << "\"" << " not found." << std::endl;
        return;
    }
    if(*(this->next->data) == data1)
    {
        LinkedList<T> *tmp, *tmp2;
        tmp = this->next;
        this->next = this->next->next;
        tmp2 = this->next;
        for (int i = this->position+1;; i++)
        {
            tmp2->position = i;
            if(tmp2->next == nullptr)
                break;
            tmp2 = tmp2->next;
        }
        
        delete tmp;
        this->size--;
        return;
    }
    this->next->remove(data1);
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

    if(this->data != nullptr)
        delete this->data;

    if(this->next != nullptr)
        delete this->next;

    this->data = nullptr;
    this->next = nullptr;
}

template<typename T>
void LinkedList<T>::reverse()
{
    if(this->data == nullptr)
        return;
    
    if(this->next == nullptr || this->next->data == nullptr)
        return;

    LinkedList<T> *tmp, *tmp2;
    tmp = this;

    for (int i = 0; i < this->size/2; i++)
    {
        tmp2 = this;

        while (tmp2->position != this->size-1-i)
            tmp2 = tmp2->next;

        this->swap(*(tmp->data), *(tmp2->data));
        tmp = tmp->next;
    }
    
}

template<typename T>
template<typename T1, typename T2>
void LinkedList<T>::swap(T1 data1, T2 data2)
{
    LinkedList<T> *aux1, *aux2, *tmp;
    aux1 = aux2 = nullptr;
    tmp = this;

    while(aux1 == nullptr || aux2 == nullptr)
    {
        if(*(tmp->data) == data1)
            aux1 = tmp;

        if(*(tmp->data) == data2)
            aux2 = tmp;
        
        if(tmp->next == nullptr)
            break;
        tmp = tmp->next;
    }

    tmp = new LinkedList(*(aux1->data));
    *(aux1->data) = *(aux2->data);
    *(aux2->data) = *(tmp->data);

    delete tmp;
    this->size--;
}

template<typename T>
int LinkedList<T>::getSize()
{
    return this->size;
}