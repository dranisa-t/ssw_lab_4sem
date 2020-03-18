#include<iostream>
using namespace std;

template <typename T>
class Vektor
{
private:
    T*Buffer;
    int Size;
public:
    Vektor();
    ~Vektor();
    /*stack functions*/
    void  display();
    void push(T);//вставка элемента в структуру;
    void pop();//выталкивание элемента из структуры;
    T at(int);//метод произвольного доступа к элементу, реализуется только для структуры вектор;
    T peek();//возврат вершины структуры (верхнего элемента);
    int count();//возврат количества элементов в структуре;
    void reverse();//смены порядка элементов в структуре на обратный (reverse);
    friend void swap(Vektor<T> &m1, Vektor<T> &m2)//обмена (swap) данными между структурами;
    {
        if (m1.Size == m2.Size) {
            for (int i = 0; i < m1.Size; i++)
            {
                T c = m1.Buffer[i];
                m1.Buffer[i] = m2.Buffer[i];;
                m2.Buffer[i] = c;
            }
        }
        else {
            T *a;
            a = new T[m1.Size];
            for (int i = 0; i < m1.Size; i++)
                a[i] = m1.Buffer[i];
            delete[] m1.Buffer;
            m1.Buffer = new T[m2.Size];
            for (int i = 0; i < m2.Size; i++)
                m1.Buffer[i] = m2.Buffer[i];
            delete[] m2.Buffer;
            m2.Buffer = new T[m1.Size];
            m2.Buffer = a;
        }
        int l;
        l = m1.Size;
        m1.Size = m2.Size;
        m2.Size = l;
    };

    friend bool operator == (Vektor<T> &m1, Vektor<T> &m2) {
        if (m1.Size != m2.Size) {
            return false;
        }
        else
        {
            int i = 0;
            do {
                if (m1.Buffer[i] != m2.Buffer[i]) return false;
                i++;
            } while ((m1.Buffer[i] == m2.Buffer[i]) && (i < m1.Size));
            return  true;
        }
    };

    friend bool operator != (Vektor<T> &m1, Vektor<T> &m2) {
        return !(m1 == m2);
    };

    friend bool operator > (Vektor<T> &m1, Vektor<T>&m2) {
        int minimum = 0;
        if (m1.Size < m2.Size) minimum = m1.Size;
        else minimum = m2.Size;
        int i = 0;
        while (i < minimum){
            if (m1.Buffer[i] < m2.Buffer[i]) return false;
            if (m1.Buffer[i] > m2.Buffer[i]) return true;
            i++;
        }

        return m1.Size > m2.Size;

    };

    friend bool operator < (Vektor<T> &m1, Vektor<T> &m2) {
        int minimum = 0;
        if (m1.Size < m2.Size) minimum = m1.Size;
        else minimum = m2.Size;
        int i = 0;
        while (i < minimum){
            if (m1.Buffer[i] > m2.Buffer[i]) return false;
            if (m1.Buffer[i] < m2.Buffer[i]) return true;
            i++;
        }

        return m1.Size < m2.Size;
    };

    friend bool operator >= (Vektor<T> &m1, Vektor<T> &m2) {
        return !(m1 < m2);
    };

    friend bool operator <= (Vektor<T> &m1, Vektor<T> &m2) {
        return !(m1 > m2);
    };
};

template <typename T>
Vektor<T>::Vektor() {
    Size = 0;
    Buffer = new T[Size];
};

template <typename T>
Vektor<T>::~Vektor() {
    delete[] Buffer;
};

template <typename T>
void Vektor<T>::display() {

    for (int i = 0; i < Size; i++)
        cout << Buffer[i] << " ";
};

template <typename T>
void  Vektor<T>::push(T a) {
    T * k = new T[Size + 1];
    for (int i = 0; i < Size; i++)
        k[i] = Buffer[i];
    k[Size] = a;
    delete[] Buffer;
    Size++;
    Buffer = k;
};
template <typename T>
void Vektor<T>::pop() {
    if (Size > 0) {
        T * k;
        k = new T[Size - 1];
        for (int i = 0; i < Size - 1; i++)
            k[i] = Buffer[i];
        delete[] Buffer;
        Size--;
        Buffer = k;
    }
    else throw std::runtime_error("vektor is empty");
};

template <typename T>
T  Vektor<T>::at(int i) {
    if ((i >= 0) && (i < Size))
        return Buffer[i];
    else throw std::runtime_error("vektor is empty");
}
template <typename T>
T Vektor<T>::peek() {
    if (Size > 0) {
        return Buffer[0];
    }
    else throw std::runtime_error("vektor is empty");
};

template <typename T>
int Vektor<T>::count() {
    return Size;
};

template <typename T>
void Vektor<T>::reverse() {
    if (Size > 0)
        for (int i = 0; i < Size / 2; i++)
        {
            T x = Buffer[i];
            Buffer[i] = Buffer[Size - 1 - i];
            Buffer[Size - 1 - i] = x;
        }
    else throw std::runtime_error("vektor is empty");
};
