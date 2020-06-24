#ifndef LABA2_1V_SIMPLY__LIST_H
#define LABA2_1V_SIMPLY_LIST_H
#include <iostream>
using namespace std;

template<typename T>
class Simply_List {
private:
    class Element {
    public:
        Element *pNext{nullptr};
        T data{ 0 };
        explicit Element(T dat, Element *Next = nullptr) {
            data = dat;
            pNext = Next;
        }
        ~Element() = default;
    };

    int Size{ 0 };
    Element *head{ nullptr };
public:
    Simply_List() = default;
    Simply_List(const std::initializer_list<T> &d);
    ~Simply_List();
    void screen();
    void push_front(T data); //adding an item to the top of the list
    void push_back(T data); // adding an item to the end of the list
    void pop_front();//deleting the first item in the list
    void pop_back();// deleting an item from the end of the list
    void instert(T data, int index);//inserting an element to any place in the structure
    void earse(int index); // deleting an element from any place in the structure
    T *begin();
    T *end();
    int count() { return Size; }//returns the number of elements in the structure
    void  merger(Simply_List<T> &List1, Simply_List<T> &List2);
    void partition(T t, Simply_List<T> &result1, Simply_List<T> &result2);

    friend std::ostream &operator<<(std::ostream &out, const Simply_List<T> &d1) {
        if (d1.head == nullptr) throw std::out_of_range("List is empty");
        Element *present = d1.head;
        out << "( ";
        while (present->Next != nullptr) {
            out << present->data << ", ";
            present = present->pNext;
        }
        out << present->data << " )";
        return out;
    };

    friend bool operator >(const Simply_List<T> &d1, const Simply_List<T> &d2) {
        Element *pres1 = d1.head;
        Element *pres2 = d2.head;
        while ((pres1->pNext != nullptr) && (pres2->pNext != nullptr)) {
            if (pres1->data < pres2->data){
                return false;
            }
            if (pres1->data > pres2->data){
                return true;
            }
            pres1 = pres1->pNext;
            pres2 = pres2->pNext;
        }
        if (pres1->data > pres1->data) {
            return true;
        }
        if (pres1->data < pres2->data) {
            return false;
        }
        return (d1.Size > d2.Size);
    };

    friend bool operator==(const Simply_List<T> &d1, const Simply_List<T> &d2) {
        Element *pres1 = d1.head;
        Element *pres2 = d2.head;
        while ((pres1->pNext != nullptr) && (pres2->pNext != nullptr)) {
            if (pres1->data != pres2->data) {
                return false;
            }
            pres1 = pres1->pNext;
            pres2 = pres2->pNext;
        }
        if (pres1->data != pres2->data) {
            return false;
        }
        return (d1.Size == d2.Size);
    };

    friend bool operator<(const Simply_List<T> &d1, const Simply_List<T> &d2) {
        return !(d1 >= d2);
    };

    friend bool operator!=(const Simply_List<T> &d1, const Simply_List<T> &d2) {
        return !(d1 == d2);
    };

    friend bool operator<=(const Simply_List<T> &d1, const Simply_List<T> &d2) {
        return !(d1 > d2);
    };

    friend bool operator>=(const Simply_List<T> &d1, const Simply_List<T> &d2) {
        return ((d1 > d2) || (d1 == d2));
    };
    T& operator[](int index);
    void clear();//clear the list
};

template<typename T>
Simply_List<T>::Simply_List(const std::initializer_list<T> &d1)
{
    for (int i = 0; i < d1.size(); i++) {
        push_back(d1.begin()[i]);
    }
}

template<typename T>
Simply_List<T>::~Simply_List()
{
    clear();
}

template<typename T>
void Simply_List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Element(data);
    }
    else{
        Element *present = this->head;
        while (present->pNext != nullptr)
        {
            present = present->pNext;
        }
        present->pNext = new Element(data);
    }
    Size++;
}

template<typename T>
void Simply_List<T>::push_front(T data)
{
    head = new Element(data, head);
    Size++;
}

template <typename T>
void Simply_List<T>::pop_front(){
    if (head == nullptr) throw std::out_of_range("list is empty");
    Element *delet = head;
    T rev = head->data;
    head = head->pNext;
    delete delet;
    Size--;
    if (Size == 0) head = nullptr;
    return rev;
}


template<typename T>
void Simply_List<T>::pop_back()
{
    if (head == nullptr) throw std::out_of_range("list is empty");

    Element *delet = nullptr;
    Element *present = this->head;
    T rev;
    while (present->pNext != nullptr)
    {   delet = present;
        present =present->pNext;
    }
    if (present != nullptr) delet->pNext = nullptr;
    rev = present->data;
    delete present;
    Size--;
    if (Size == 0) {
        head = nullptr;
    }
    return rev;
}

template<typename T>
void Simply_List<T>::instert(T data, int index)
{
    if ((index > Size) || (index < 0)) throw std::out_of_range("index less than zero, does not match the minimum list size");
    if (index == 0)	push_front(data);
    else {
        Element *previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Element *newElement = new Element(data, previous->pNext);
        previous->pNext = newElement;
        Size++;
    }
}

template<typename T>
void Simply_List<T>::earse(int index)
{
    if ((index < 0) || (index >= Size)) throw std::out_of_range("index is more then size of list or will be positive number");
    if (index == 0){
        pop_front();
    }
    else
    {
        Element *previous = this->head;
        for (int i = 0; i < index - 1; i++){
            previous = previous->pNext;
        }
        Element *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
void Simply_List<T>::clear() {
    while (Size)
        pop_front();
    head = nullptr;

}

template<class T>
T& Simply_List<T>::operator[](int index)
{
    if ((index >= Size) || (index < 0)) throw std::out_of_range("index is more then size of list or will be positive number");
    int count = 0;
    Element *present = head;
    while (present != nullptr) {
        if (count == index) {
            return present->data;
        }
        present = present->pNext;
        count++;
    }
    throw std::out_of_range("out of range");
}


template<typename T>
T * Simply_List<T>::begin() {
    return &head->data;
}
template<typename T>
T * Simply_List<T>::end(){
    Element *present = head;
    while (present->pNext != nullptr) {
        present = present->pNext;
    }
    return &present->data;
}

template<typename T>
void Simply_List<T>::screen() {
    Element *present = this->head;
    cout << endl;
    while (present->pNext != nullptr) {
        cout << present->data << " ";
        present = present->pNext;
    }
    cout << present->data << " ";
}


template<typename T>
void Simply_List<T>::merger(Simply_List<T> &List1, Simply_List<T> &List2) {
    Element *present1 = List1.head;
    Element *present2 = List2.head;
    int t1 = 0;
    int t2 = 0;
    while ((t1 != List1.Size) && (t2 != List2.Size))
    {
        if (present1->data <= present2->data) {
            this->push_back(present1->data);
            t1++;
            if (t1 != List1.Size) {
                present1 = present1->pNext;
            }
            if (present2->data < present1->data) {
                this->push_back(present2->data);
                t2++;
                if (t2 != List2.Size) {
                    present2 = present2->pNext;
                }
            }

            if ((t1 == List1.Size) && (t2 != List2.Size)) {
                while (t2 != List2.Size) {
                    this->push_back(present2->data);
                    t2++;
                    if (t2 != List2.Size) {
                        present2 = present2->pNext;
                    }
                }
            }

            if ((t2 == List2.Size) && (t1 != List1.Size)) {
                while (t1 != List1.Size) {
                    this->push_back(present1->data);
                    t1++;
                    if (t1 != List1.Size) {
                        present1 = present1->pNext;
                    }
                }
            }
        }
    }
}

template<typename T>
void Simply_List<T>::partition(T t, Simply_List<T> &rezult1, Simply_List<T> &rezult2) {
    Element *present = this->head;
    while (present->pNext != nullptr) {
        if (present->data < t) {
            rezult1.push_back(present->data);
        }
        else {
            rezult2.push_back(present->data);
        }
        present = present->pNext;
    }
    if (present->data < t) {
        rezult1.push_back(present->data);
    }
    else {
        rezult2.push_back(present->data);
    }
}
#endif
