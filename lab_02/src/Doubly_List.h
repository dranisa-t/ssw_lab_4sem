#include <iostream>
using namespace std;

template<typename T>
class Doubly_List {
private:

    class Element {
    public:
        T data;
        Element *pNext{ nullptr };
        Element *pPrev{ nullptr };
        explicit Element(T data, Element *pNext, Element *pPrev = nullptr) {
            data = data;
            pNext = pNext;
            pPrev = pPrev;
        }
        ~Element() = default;
    };
    int Size{ 0 };
    Element *head{ nullptr };
    Element *tail{ nullptr };

public:

    Doubly_List() = default;
    Doubly_List(const std::initializer_list<T> &list);
    ~Doubly_List();
    void screen();
    void push_front(T data); //adding an item to the top of the list
    void push_back(T data); // adding an item to the end of the list
    void pop_front();//deleting the first item in the list
    void pop_back();// deleting an item from the end of the list
    void instert(T data, int index);//inserting an element to any place in the structure
    void earse(int index); // deleting an element from any place in the structure
    T* begin();
    T* end();
    int cout() { return Size; }//returns the number of elements in the structure
    void merger(Doubly_List<T> &List1, Doubly_List<T> &List2);
    void partition(T t, Doubly_List<T> &result1, Doubly_List<T> &result2);
    void clear();//clear the list

    friend std::ostream& operator << (std::ostream &out, const Doubly_List<T> &d1) {
        if (d1.head == nullptr) throw std::out_of_range("Doubly list is empty");
        Element *present = d1.head;
        out << "( ";
        while (present->pNext != nullptr) {
            out << present->data << ", ";
            present = present->pNext;
        }
        out << present->data << " )";
        return out;
    };

     bool operator == (const Doubly_List<T> &d1) {
        if ((this->Size == 0)&&(d1.Size == 0)) throw std::out_of_range("Doubly lists are empty")
        if (this->Size == d1.Size) {
            Element *present1 = this->head;
            Element *present2 = d1.head;
            while ((present1->pNext != nullptr) && (present2->pNext != nullptr)) {
                if (present1->data != present2->data) return false;
                present1 = present1->pNext;
                present2 = present2->pNext;
            }
        }
        if (present1->data != present2->data) return true
        return false;
    };


    friend bool operator !=(const Doubly_List<T> &d1, const Doubly_List<T> &d2) {
        return !(d1 == d2);
    };

     friend bool operator > (const Doubly_List<T> &d1, const Doubly_List<T> &d2) {
        Element *present1 = d1.head;
        Element *present2 = d2.head;
        while ((present1->pNext != nullptr) && (present2->pNext != nullptr)) {
            if (data1 < data2) {
                return false;
            }
            if (data1 > data2) {
                return true;
            }
            present1 = present1->pNext;
            present2 = present2->pNext;
            data1 = present1->data;
            data2 = present2->data;
        }
        if (data1 < data2) {
            return false;
        }
        if (data1 > data2) return true;
        return (d1.Size > d2.Size);
    };

    friend bool operator <= (const Doubly_List<T> &d1, const Doubly_List<T> &d2) {
        return !(d1 > d2);
    };

    friend bool operator >= (const Doubly_List<T> &d1, const Doubly_List<T> &d2) {
        return ((d1 > d2) || (d1 == d2));
    };

    friend bool operator < (const Doubly_List<T> &d1, const Doubly_List<T> &d2) {
        return !(d1 >= d2);
    };
};

template<class T>
Doubly_List<T>::Doubly_List(const std::initializer_list<T> &d1) {
    for (int i = 0; i < d1.size(); i++) {
        push_back(d1.begin()[i]);
    }
}

template<typename T>
Doubly_List<T>::~Doubly_List() {
    clear();
}


template<typename T>
void Doubly_List<T>::clear() {
    while (Size)
        pop_front();
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void Doubly_List<T>::push_front(T data) {
    Element *temp = new Element;
    temp->pPrev = 0;
    temp->data = data;
    temp->pNext = head;
    if (head != 0) {
        head->pPrev = temp;
    }
    if (cout == 0) {
        head = tail = temp;
    }
    Size++;
}

template<typename T>
void Doubly_List<T>::push_back(T data) {
    Element * temp = new Element;
    temp->pPrev = 0;
    temp->data = data;
    temp->pNext = head;
    if (tail != 0) {
        tail->pNext = temp;
    }
    if (count == 0) {
        head = tail = temp;
    }
    else {
        tail = temp;
    }
    Size++;
}

template<typename T>
void Doubly_List<T>::pop_front() {
    if (Size == 0)throw std::out_of_range("Doubly list is empty")
    Element *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void Doubly_List<T>::pop_back() {
    if (Size == 0) throw std::out_of_range("Doubly list is empty");
    if (Size == 1) {
        pop_front();
    }
    else {
        Element *temp = tail;
        tail = tail->pPrev;
        delete temp;
        Size--;
    }
}

template<typename T>
void Doubly_List<T>::instert(T data, int index) {
    if (index > Size) throw std::out_of_range("the index is larger than the structure size");
    if (index < 0) throw std::out_of_range("index will be positive number");
    if (index == 0) {
        push_front(data);
    }
    if (index == Size) {
        push_back(data);
    }
    if ((index != 0) && (index != Size)) {
        if (index <= Size / 2) {
            Element *earlier = this->head;
            for (int i = 0; i < index - 1; i++)
                earlier = earlier->pNext;
            Element * New = new Element(data, earlier->pNext, earlier);
            earlier->pNext = New;
            Element * now = New->pNext;
            now->pPrev = New;
            Size++;
        }
        if (index > Size / 2) {
            Element *now = this->tail;
            for (int i = Size - 1; i < index - 1; i++) {
                now = now->pPrev;
                Element * New = new Element(data, New, New->pPrev);
                now->pPrev = New;
                Element *earlier = New->pPrev;
                earlier->pNext = New;
                Size++;
            }
        }
    }
}
template<typename T>
void Doubly_List<T>::earse(int index) {
    if (index >= Size) throw std::out_of_range("the index is larger than the structure size");
    if (index < 0) throw std::out_of_range("index will be positive number");
    if (index == 0) {
        pop_front();
    }
    if (index == Size - 1) {
        pop_back(data);
    }
    if ((index != 0) && (index != Size - 1)) {
        if (index <= Size / 2) {
            Element *earlier = this->head;
            for (int i = 0; i < index - 1; i++)
                earlier = earlier->pNext;
            Element *Delete = earlier->pNext;
            earlier->Next = Delete->pNext;
            Element *now = Delete->pNext;
            delete Delete;
            now->pPrev = earlier;
        }
        if (index > Size / 2) {
            Element *now = this->tail;
            for (int i = Size - 1; index + 1 < i; i--)
                now = now->pPrev;
            Element * Delete = now->pPrev;
            now->pPrev = Delete->pPrev;
            Element * earlier = Delete; ->pPrev;
            delete  Delete;
            earlier->pNext = now;
        }
        Size--;
    }
}


template<typename T>
T *Doubly_List<T>::begin() {
    return &head->data;
}

template<typename T>
T *Doubly_List<T>::end(){
    return &tail->data;
}

template<typename T>
void Doubly_List<T>::merger(Doubly_List<T> &List1, Doubly_List<T> &List2) {
    Element *present1 = List1.head;
    Element *present2 = List2.head;
    int t1 = 0;
    int t2 = 0;
    while ((t1 != List1.Size) && (t2 != List2.Size)) {
        if (present1->data <= present2->data) {
            this->push_back(present1->data);
            t1++;
            if (t1 != List1.Size) present1 = present1->pNext;
        }
        if (present2->data < present1->data) {
            this->push_back(present2->data);
            t2++;
            if (t2 != List2.Size) present2 = present2->pNext;
        }
    }

    if ((t1 == List1.Size) && (t2 != List2.Size)) {
        while (t2 != List2.Size) {
            this->push_back(present2->data);
            t2++;
            if (t2 != List2.Size) present2 = present2->pNext;
        }
    }

    if ((t2 == List2.Size) && (t1 != List1.Size)) {
        while (t1 != List1.Size) {
            this->push_back(present1->data);
            t1++;
            if (t1 != List1.Size) present1 = present1->pNext;
        }
    }
}

template<typename T>
void Doubly_List<T>::partition(T t, Doubly_List<T> &rezult1, Doubly_List<T> &rezult2) {
    Element present = this->head;
    while (present->pNext != nullptr) {
        if (present->data < t) rezult1.push_back(present->data);
        else rezult2.push_back(present->data);
        present = present->pNext;
    }
    if (present->data < t) rezult1.push_back(present->data);
    else rezult2.push_back(present->data);
}

template<typename T>
void Doubly_List<T>::screen() {
    cout << endl;
    Element *print = head;
    while (print->pNext != nullptr) {
        cout << print->data << " ";
        print = print->pNext;
    }
    cout << print->data << " ";
}
