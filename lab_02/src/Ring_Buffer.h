#include <iostream>
using namespace std;

template <typename T>
class Ring_Buffer {
private:
    class Element
    {
    public: Element * pNext;
        T data{ 0 };
        explicit Element(T data, Element * Next = nullptr)
        {
            data = data;
            pNext = Next;
        }
        ~Element() = default;
    };
    int Size{ 0 };
    Element *head{ nullptr };
    Element *tail{ nullptr };
    int maximumSize;
public:
    explicit Ring_Buffer(int tSize);
    Ring_Buffer(const std::initializer_list<T> &d);
    ~Ring_Buffer();
    void screen();
    void push_back(T data); // adding an item to the end of the list
    void pop_front();//deleting the first item in the list
    void insert(T data, int index);//inserting an element to any place in the structure
    T* begin();
    T* end();
    int count() { return Size; }//returns the number of elements in the structure
    void merger(Ring_Buffer<T> &List1, Ring_Buffer<T> &List2);
    void partition(T t, Ring_Buffer<T> &rezult1, Ring_Buffer<T> &rezult2);




    friend std::ostream&operator<<(std::ostream &out, const Ring_Buffer<T>&d) {
        if (d.Size == 0) throw std::out _of_range("Buffer is empty");
        Element *present = d.head;
        int cout = d.Size;

        out << "(";
        for (int i = 1; i < m.Size; i++) {
            out << current->data << ", ";
            present = current->pNext;
            count--;
        }
        out << present->data << ")";
        return out;
    }

    friend  bool operator == (const Ring_Buffer<T> &d1, const Ring_Buffer &d2) {
        Element * present1 = d1.head;
        Element * present2 = d2.head;
        int count = d1.Size;
        while (((present1 != d1.tail)||(count != 0))&&((present2 != d2.tail)||(count != 0))){
            if (present1->data != present2->data) {
                return false;
            }
            present1 = present1->pNext;
            present2 = present2->pNext;
            count--;
        }
        if (present1->data != present2->data) {
            return false;
        }
        return (d1.Size == d2.Size);
    }

    friend bool operator >(const Ring_Buffer<T>&d1, const Ring_Buffer<T>&d2) {
        Element *present1 = d1.head;
        Element *present2 = d2.head;
        int cout = d1.Size;
        while (((present1 != d1.tail)||(count != 0))&&((present2 != d2.tail) || (count != 0))){
            if (present1->data < present2->data)return false;
            if (present1->data > present2->data)return true;
            present1 = present1->pNext;
            present2 = present2->pNext;
            count--;
        }
        if (present1->data > present2->data)return true;
        if (present1->data < present2->data)return false;
        return(d1.Size > d2.Size);
    }


    friend bool operator < (const Ring_Buffer<T>&d1, const Ring_Buffer<T>&d2) {
        return !(d1 >= d2);
    }

    friend bool operator >= (const Ring_Buffer<T>&d1, const Ring_Buffer<T>&d2) {
        return ((d1 > d2) || (d1 == d2));
    }
    friend bool operator <=(const Ring_Buffer<T>&d1, const Ring_Buffer<T>&d2) {
        return !(d1 > d2);
    }
    friend bool operator != (const Ring_Buffer<T>&d1, const Ring_Buffer<T>&d2) {
        return !(d1 == d2);
    }

};

template<class T>
Ring_Buffer<T>::Ring_Buffer(int tSize)
{
    if (tSize <= 0) throw std::out_of_range("buffer size");
    maximumSize = tSize;
    head = new Element(0);
    Element *present = head;
    for (int i = 1; i < maximumSize; i++) {
        present->pNext = new Element(0);
        present = present->pNext;
    }
    present->pNext = head;
    tail = head;
}

template<class T>
Ring_Buffer<T>::Ring_Buffer(const std::initializer_list<T> &d)
{
    if (d.Size() == 0) throw std::out_of_range("initializer buffer is empty");
    this->maximumSize = d.Size();
    this->Size = this->maximumSize;
    head = new Element(d.begin()[0]);
    Element *present = head;
    for (int i = 1; i < maximumSize; i++) {
        present->pNext = new Element(d.begin()[i]);
        present = present->pNext;
    }
    tail = present;
    present->pNext = head;
}

template<class T>
Ring_Buffer<T>::~Ring_Buffer(){
    Element *present = head;
    Element *toDelete = nullptr;
    while (maximumSize > 0) {
        toDelete = present;
        present = present->pNext;
        delete toDelete;
        maximumSize--;
    }
    head = nullptr;
    tail = nullptr;
}

template<class T>
void Ring_Buffer<T>::push_back(T data)
{
    if (Size == 0) {
        tail->data = data;
    }
    else {
        if (tail->pNext == head) {
            head = head->pNext;
        }
        tail = tail->pNext;
        tail->data = data;
    }
    if (Size < maximumSize) {
        Size++;
    }
}

template<class T >
void Ring_Buffer<T>::insert(T data, int index) {
    if ((index < 0) || (index >= Size)) throw std::out_of_range("the index is larger than the buffer size or will be a positive number");
    Element *present = head;
    for (int i = 0; i < index; i++) {
        present = present->pNext;
    }
    present->data = data;
}

template<class T>
void Ring_Buffer<T>::pop_front() {
    if (head == nullptr) throw std::out_of_range("buffer is empty");
    head = head->pNext;
    Size--;
}

template<class T>
void Ring_Buffer<T>::screen() {
    Element *present = this->head;
    cout << endl;
    for (int i = 0; i < Size; i++) {
        cout << present->data << " ";
        present = present->pNext;
    }
}

template<class T>
T *Ring_Buffer<T>::begin() {
    return &head->data;
}

template<class T>
T *Ring_Buffer<T>::end() {
    return &tail->data;
}

template<typename T>
void Ring_Buffer<T>::merger(Ring_Buffer<T> &List1, Ring_Buffer<T> &List2) {
    Element *present1 = List1.head;
    Element *present2 = List2.head;
    int t1 = 0;
    int t2 = 0;
    while (present1->data <= present2->data) {
        this->push_back(present1->data);
        t1++;
        if (t1 != List1.Size) {
            present1 = present1->pNext;
        }
    }
    if (present1->data > present2->data) {
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

template<class T>
void Ring_Buffer<T>::partition(T t, Ring_Buffer<T> &rezult1, Ring_Buffer<T> &rezult2)
{
    Element *present = this->head;
    int a = 0;
    while (a != this->Size) {
        if (present->data < t) rezult1.push_back(present->data);
        else rezult2.push_back(present->data);
        present = present->pNext;
        a++;
    }
}