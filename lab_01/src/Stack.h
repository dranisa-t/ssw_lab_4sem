#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    T *Buffer1;
    int Size1;
public:
    Stack();
    ~Stack();
    void  display();
    void push(T);//вставка элемента в структуру;
    void pop();//выталкивание элемента из структуры;
    T peek();//возврат вершины структуры (верхнего элемента);
    int count();//возврат количества элементов в структуре;
    void reverse();//смены порядка элементов в структуре на обратный (reverse);
    friend void swap(Stack<T> &m1, Stack<T> &m2)//обмена (swap) данными между структурами;
    {
        if (m1.Size1 == m2.Size1) {
            for (int i = 0; i < m1.Size1; i++)
            {
                T c = m1.Buffer1[i];
                m1.Buffer1[i] = m2.Buffer1[i];;
                m2.Buffer1[i] = c;
            }
        }
        else {
            T *a;
            a = new T[m1.Size1];
            for (int i = 0; i < m1.Size1; i++)
                a[i] = m1.Buffer1[i];
            delete[] m1.Buffer1;
            m1.Buffer1 = new T[m2.Size1];
            for (int i = 0; i < m2.Size1; i++)
                m1.Buffer1[i] = m2.Buffer1[i];
            delete[] m2.Buffer1;
            m2.Buffer1 = new T[m1.Size1];
            m2.Buffer1 = a;
        }
        int l;
        l = m1.Size1;
        m1.Size1 = m2.Size1;
        m2.Size1 = l;
    };
    //////////////////
    friend bool operator == (Stack<T> &m1, Stack<T> &m2)
    {
        if (m1.Size1 != m2.Size1) {
            return false;
        }
        else
        {
            int i = 0;
            do {
                if (m1.Buffer1[i] != m2.Buffer1[i]) return false;
                i++;
            } while ((m1.Buffer1[i] == m2.Buffer1[i]) && (i < m1.Size1));
            return  true;
        }
    };
    friend bool operator != (Stack<T> &m1, Stack<T> &m2)
    {
        return !(m1 == m2);
    };
    friend bool operator > (Stack<T> &m1, Stack<T>&m2)
    {
        int minimum = 0;
        if (m1.Size1 < m2.Size1) minimum = m1.Size1;
        else minimum = m2.Size1;
        int i = 0;
        do {
            if (m1.Buffer1[i] < m2.Buffer1[i]) return false;
            if (m1.Buffer1[i] > m2.Buffer1[i]) return true;
            i++;
        } while ((m1.Buffer1[i] == m2.Buffer1[i]) && (i < minimum));
        return m1.Size1 > m2.Size1;
    };
    friend bool operator >= (Stack<T> &m1, Stack<T> &m2)
    {
        return !(m1 < m2);
    };
    friend bool operator < (Stack<T> &m1, Stack<T> &m2)
    {

        int minimum = 0;
        if (m1.Size1 < m2.Size1) minimum = m1.Size1;
        else minimum = m2.Size1;
        int i = 0;
        do {
            if (m1.Buffer1[i] > m2.Buffer1[i]) return false;
            if (m1.Buffer1[i] < m2.Buffer1[i]) return true;
            i++;
        } while ((m1.Buffer1[i] == m2.Buffer1[i]) && (i < minimum));

        return m1.Size < m2.Size;
    };

    friend bool operator <= (Stack<T> &m1, Stack<T> &m2)
    {
        return !(m1 > m2);
    };
};
template <typename T>
Stack<T>::Stack()
{
    Size1 = 0;
    Buffer1 = new T[Size1];
};

template <typename T>
Stack<T>::~Stack()
{
    delete[] Buffer1;
};
template <typename T>
void Stack<T>::display()
{
    cout << "\nVyvod elem Stack\n";
    for (int i = Size1 - 1; i >= 0; i--)
        cout << Buffer1[i] << endl;
};
template <typename T>

void  Stack<T>::push(T a)
{
    T * k;
    k = new T[Size1 + 1];
    for (int i = 0; i < Size1; i++)
        k[i] = Buffer1[i];
    k[Size1] = a;
    delete[] Buffer1;
    Size1++;
    Buffer1 = k;
};
template <typename T>
void Stack<T>::pop()
{
    if (Size1 > 0) {
        T * k;
        k = new T[Size1 - 1];
        for (int i = 0; i < Size1 - 1; i++)
            k[i] = Buffer1[i];
        delete[] Buffer1;
        Size1--;
        Buffer1 = k;
    }
    else throw std::runtime_error("stack is empty");
};
template <typename T>
T Stack<T>::peek()
{
    if (Size1 > 0) return Buffer1[Size1 - 1];
    else throw std::runtime_error("stack is empty");
};
template <typename T>
int Stack<T>::count()
{
    return Size1;
};
template <typename T>
void Stack<T>::reverse()
{
    if (Size1 > 0)
        for (int i = 0; i < Size1 / 2; i++)
        {
            T x = Buffer1[i];
            Buffer1[i] = Buffer1[Size1 - 1 - i];
            Buffer1[Size1 - 1 - i] = x;
        }
    else throw std::runtime_error("stack is empty");
};