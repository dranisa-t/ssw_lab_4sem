#include "pch.h"
# include <iostream>
using namespace std;

template <typename T>
class Vektor
{
private:
	T*Buffer;
	int Size;
public:
	Vektor(int nSize);
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
		T a;
		for (int i = 0; i < m1.Size; i++)
		{
			a = m1.Buffer[i];
			m1.Buffer[i] = m2.Buffer[i];;
			m2.Buffer[i] = a;
		}
	};
	
	friend bool operator == ( Vektor<T> &m1, Vektor<T> &m2)
	{
		if (m1.Size != m2.Size) {
			return false;
		}
		else
		{
			int i = 0;
			do{			
				if (m1.Buffer[i] != m2.Buffer[i]) return false;
				i++;
			}while ((m1.Buffer[i] == m2.Buffer[i]) && (i < m1.Size));
			return  true;
		}
	};
	friend bool operator != ( Vektor<T> &m1, Vektor<T> &m2)
	{
		return !(m1 == m2);
	};
	friend bool operator > ( Vektor<T> &m1,  Vektor<T>&m2)
	{
		int minimum = 0;
		if (m1.Size < m2.Size) minimum = m1.Size;
		else minimum = m2.Size;
		int i = 0;
		do {
			if (m1.Buffer[i] < m2.Buffer[i]) return false;
			if (m1.Buffer[i] > m2.Buffer[i]) return true;
			i++;
		} while ((m1.Buffer[i] == m2.Buffer[i]) && (i < minimum));
		
		if (m1.Size > m2.Size)
		{
			return true;
		}
		return false;
		
	};
	friend bool operator < ( Vektor<T> &m1, Vektor<T> &m2)
	{
		int minimum = 0;
		if (m1.Size < m2.Size) minimum = m1.Size;
		else minimum = m2.Size;
		int i = 0;
		do {
			if (m1.Buffer[i] > m2.Buffer[i]) return false;
			if (m1.Buffer[i] < m2.Buffer[i]) return true;
			i++;
		} while ((m1.Buffer[i] == m2.Buffer[i]) && (i < minimum));

		if (m1.Size < m2.Size)
		{
			return true;
		}
		return false;
	};
	friend bool operator >= ( Vektor<T> &m1, Vektor<T> &m2)
	{
		return !(m1 < m2);
	};
	friend bool operator <= (Vektor<T> &m1, Vektor<T> &m2)	{
		return !(m1 > m2);
	};
};
template <typename T>
Vektor<T>::Vektor(int nSize)
{
	Size = nSize;
	Buffer = new T[Size];
};
template <typename T>
Vektor<T>::~Vektor()
{
	delete[] Buffer;
};
template <typename T>
void Vektor<T>::display()
{
	cout << "\nVyvod elem Vektora\n";
	for (int i = 0; i < Size; i++)
		cout << Buffer[i] << " ";
};
template <typename T>
void  Vektor<T>::push( T a)
{
	T * k;
	k = new T[Size + 1];
	for (int i = 0; i < Size; i++)
		k[i] = Buffer[i];
	k[Size] = a;
	delete Buffer;
	Size++;
	Buffer = k;
};
template <typename T>
void Vektor<T>::pop()
{
	T * k;
	k = new T[Size - 1];
	for (int i = 0; i < Size-1; i++)
		k[i] = Buffer[i];
	delete Buffer;
	Size--;
	Buffer = k;
};
template <typename T>
T  Vektor<T>::at(int i)
{
	if ((i < 0) || (i >= Size))
	{ return  0; }
	else return Buffer[i];
};
template <typename T>
T Vektor<T>::peek()
{
	cout <<endl<< "Vershina vektora:";
	cout << endl << Buffer[0] << endl;
	return Buffer[0];
};
template <typename T>

int Vektor<T>::count()
{
	cout <<endl<< Size;
	return Size;
};
template <typename T>
void Vektor<T>::reverse() 
{
	for (int i = 0; i < Size / 2; i++)
	{
		T x = Buffer[i];
		Buffer[i] = Buffer[Size - 1 - i];
		Buffer[Size - 1 - i] = x;
	}
};

//-------------------------///

template <typename T>
class Stack
{
private:
	T *Buffer1;
	int Size1;
public:
	Stack(int nSize);
	~Stack();
	void  display();
	void push(T);//вставка элемента в структуру;
	void pop();//выталкивание элемента из структуры;
	T peek();//возврат вершины структуры (верхнего элемента);
	int count();//возврат количества элементов в структуре;
	void reverse();//смены порядка элементов в структуре на обратный (reverse);
	friend void swap(Stack<T> &m1, Stack<T> &m2)//обмена (swap) данными между структурами;
	{
		T a;
		for (int i = 0; i < m1.Size1; i++)
		{
			a = m1.Buffer1[i];
			m1.Buffer1[i] = m2.Buffer1[i];;
			m2.Buffer1[i] = a;
		}
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

		if (m1.Size1 > m2.Size1)
		{
			return true;
		}
		return false;

	};
	friend bool operator >= ( Stack<T> &m1, Stack<T> &m2)
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

		if (m1.Size1 < m2.Size1)
		{
			return true;
		}
		return false;
	};

	friend bool operator <= (Stack<T> &m1, Stack<T> &m2)
	{
		return !(m1 > m2);
	};
};
template <typename T>
Stack<T>::Stack(int nSize)
{
	Size1 = nSize;
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
	for (int i = Size1-1; i >= 0; i--)
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
	delete Buffer1;
	Size1++;
	Buffer1 = k;
};
template <typename T>
void Stack<T>::pop()
{
	T * k;
	k = new T[Size1 - 1];
	for (int i = 0; i < Size1-1; i++)
		k[i] = Buffer1[i];
	delete Buffer1;
	Size1--;
	Buffer1 = k;
};
template <typename T>
T Stack<T>::peek()
{ 
	cout << endl << Buffer1[Size1-1];
	return Buffer1[Size1 - 1];
};
template <typename T>
int Stack<T>::count()
{
	cout <<endl<< Size1;
	return Size1;
};
template <typename T>
void Stack<T>::reverse()
{
	for (int i = 0; i < Size1 / 2; i++)
	{
		T x = Buffer1[i];
		Buffer1[i] = Buffer1[Size1 - 1 - i];
		Buffer1[Size1 - 1 - i] = x;
	}
};
////////////////
template <typename T>
class Queue
{
private:
	T*Buffer;
	int Size;
	int n{ 0 };
public:
	Queue(int nSize);
	~Queue();
	void  display();
	void push(T);//вставка элемента в структуру;
	void pop();//выталкивание элемента из структуры;
	T peek();//возврат вершины структуры (верхнего элемента);
	int count();//возврат количества элементов в структуре;
	void reverse();//смены порядка элементов в структуре на обратный (reverse);
	friend void swap(Queue<T> &m1, Queue<T> &m2)//обмена (swap) данными между структурами;
	{
		T a;
		for (int i = 0; i < m1.Size; i++)
		{
			a = m1.Buffer[i];
			m1.Buffer[i] = m2.Buffer[i];;
			m2.Buffer[i] = a;
		}
	};
	/////////////////////////////
	friend bool operator == (Queue<T> &m1, Queue<T> &m2)
	{
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
	friend bool operator != (Queue<T> &m1, Queue<T> &m2)
	{
		return !(m1 == m2);
	};
	friend bool operator > (Queue<T> &m1, Queue<T>&m2)
	{
		int minimum = 0;
		if (m1.Size < m2.Size) minimum = m1.Size;
		else minimum = m2.Size;
		int i = 0;
		do {
			if (m1.Buffer[i] < m2.Buffer[i]) return false;
			if (m1.Buffer[i] > m2.Buffer[i]) return true;
			i++;
		} while ((m1.Buffer[i] == m2.Buffer[i]) && (i < minimum));

		if (m1.Size > m2.Size)
		{
			return true;
		}
		return false;
	
	};
	friend bool operator >= (Queue<T> &m1, Queue<T> &m2)
	{
		return !(m1 < m2);
	};
	friend bool operator < (Queue<T> &m1, Queue<T> &m2)
	{

		int minimum = 0;
		if (m1.Size < m2.Size) minimum = m1.Size;
		else minimum = m2.Size;
		int i = 0;
		do {
			if (m1.Buffer[i] > m2.Buffer[i]) return false;
			if (m1.Buffer[i] < m2.Buffer[i]) return true;
			i++;
		} while ((m1.Buffer[i] == m2.Buffer[i]) && (i < minimum));

		if (m1.Size < m2.Size)
		{
			return true;
		}
		return false;
	};

	friend bool operator <= (Queue<T> &m1, Queue<T> &m2)
	{
		return !(m1 > m2);
	};
};
template <typename T>
Queue<T>::Queue(int nSize)
{
	Size = nSize;
	Buffer = new T[Size];
};
template <typename T>
Queue<T>::~Queue()
{
	delete[] Buffer;
};
template <typename T>
void Queue<T>::display()
{
	cout << "\nVyvod elem Queue\n";
	for (int i =0; i <Size; i++)
		cout << Buffer[i] << " ";
};
template <typename T>
void  Queue<T>::push(T a)
{
	T * k;
	k = new T[Size + 1];
	for (int i = 0; i < Size; i++)
		k[i] = Buffer[i];
	k[Size] = a;
	delete[] Buffer;
	Size++;
	Buffer = k;
};
template <typename T>
void Queue<T>::pop()
{
	T * k;
	k = new T[Size - 1];
	for (int i = 1; i < Size; i++)
		k[i-1] = Buffer[i];
	delete[] Buffer;
	Size--;
	Buffer = k;
};
template <typename T>
T Queue<T>::peek()
{    
	return Buffer[0];
};
template <typename T>
int Queue<T>::count()
{
	cout << endl << Size;
	return Size;
};
template <typename T>
void Queue<T>::reverse()
{
	for (int i = 0; i < Size / 2; i++)
	{
		T x = Buffer[i];
		Buffer[i] = Buffer[Size - 1 - i];
		Buffer[Size - 1 - i] = x;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	int m, k, s1, s2;
	float n;
	int VSQ[2] = { 0,0 };
	Vektor <float> vektor(0), vektor1(0);
	Stack <float> stack(0), stack1(0);
	Queue <float> queue(0), queue1(0);
	cout << "Выберите структуру:" << endl;
	cout << "1.Вектор\n2.Стек\n3.Очередь" << endl;
	cin >> k;
	switch (k)
	{
	case 1: {
		cout << "Выберите тип вектора:\n1.int\n2.float\n";
		cin >> s1;
		if (s1 == 1)
		{
			Vektor<int> vektor(0);
		}
		cout << "\nВыберите действие для 1 Вектора :\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
		cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
		cout << "7.Выход\n";
		cin >> s2;
		while (s2 != 7)
		{
			if (s2 == 1) {
				if (s1 == 1) { vektor.push(rand()); }
				else { vektor.push(rand() / 10); }
				VSQ[0]++;
				vektor.display();
			}
			if ((s2 == 2)&(VSQ[0] != 0))
			{
				vektor.pop();
				VSQ[0]--;
				vektor.display();
			}
			if ((s2 == 3)&(VSQ[0] != 0))
			{
				n = vektor.peek();
			}
			if ((s2 == 4)&(VSQ[0] != 0))
			{
				m = vektor.count();
			}
			if ((s2 == 5)&(VSQ[0] != 0)) {
				vektor.reverse();
				vektor.display();
			}
			if ((s2 == 6)&(VSQ[0] != 0)) {
				int i = rand() % VSQ[0] + 1;
				n = vektor.at(i);
			}
			cout << "\nВыберите действие:\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
			cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
			cout << "7.Выход\n";
			cin >> s2;
		}
		cout << "\nВыберите действие для 2 Вектора:\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
		cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
		cout << "7.Выход\n";
		cin >> s2;
		while (s2 != 7)
		{
			if (s2 == 1)
			{
				if (s1 == 1) { vektor1.push(rand() ); }
				else { vektor1.push(rand() / 10); }
				VSQ[1]++;
				vektor1.display();
			}
			if ((s2 == 2)&(VSQ[1] != 0))
			{
				vektor1.pop();
				VSQ[1]--;
				vektor1.display();
			}
			if ((s2 == 3)&(VSQ[1] != 0))
			{
				n = vektor1.peek();
			}
			if ((s2 == 4)&(VSQ[1] != 0)) {
				m = vektor1.count();
			}
			if ((s2 == 5)&(VSQ[1] != 0)) {
				vektor1.reverse();
				vektor1.display();
			}
			if ((s2 == 6)&(VSQ[1] != 0))
			{
				int l = rand() % VSQ[1] + 1;
				n = vektor1.at(l);
			}
			cout << "\nВыберите действие для 2 Вектора:\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
			cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
			cout << "7.Выход\n";
			cin >> s2;
		}

		cout << "\n1Вектор";
		vektor.display();
		cout << "\n2Вектор";
		vektor1.display();
		cout << "\nРавны ли стркутуры:";
		if (vektor == vektor1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\nНеравны ли структуры";
		if (vektor != vektor1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Вектор > 2 Вектора: ";
		if (vektor > vektor1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Вектор >= 2 Вектора: ";
		if (vektor >= vektor1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Вектор < 2 Вектора: ";
		if (vektor < vektor1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Вектор <= 2 Вектора: ";
		if (vektor <= vektor1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Вектор\n";
		vektor.display();
		cout << "\n2 Вектор\n";
		vektor1.display();
		if (VSQ[0] == VSQ[1])
		{
			cout << "\nОбмен данными между структурами:";
			swap(vektor, vektor1);
			cout << "\n1 Вектор";
			vektor.display();
			cout << "\n2 Вектор";
			vektor1.display();
		}
		break;
	}

	case 2: {
		cout << "Выберите тип Стека:\n1.int\n2.float\n";
		cin >> s1;
		if (s1 == 1)
		{
			Stack<int> stack(0);
		}
		cout << "\nВыберите действие для 1 Стека :\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
		cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
		cout << "7.Выход\n";
		cin >> s2;
		while (s2 != 7)
		{
			if (s2 == 1) {
				if (s1 == 1) { stack.push(rand()); }
				else { stack.push(rand() / 10); }
				VSQ[0]++;
				stack.display();
			}
			if ((s2 == 2)&(VSQ[0] != 0))
			{
				stack.pop();
				VSQ[0]--;
				stack.display();
			}
			if ((s2 == 3)&(VSQ[0] != 0))
			{
				n = stack.peek();
			}
			if ((s2 == 4)&(VSQ[0] != 0)) {
				m = stack.count();
			}
			if ((s2 == 5)&(VSQ[0] != 0)) {
				stack.reverse();
				stack.display();
			}
			cout << "\nВыберите действие:\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
			cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
			cout << "7.Выход\n";
			cin >> s2;
		}
		cout << "\nВыберите действие для 2 Стека:\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
		cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
		cout << "7.Выход\n";
		cin >> s2;
		while (s2 != 7)
		{
			if (s2 == 1)
			{
				if (s1 == 1) { stack1.push(rand()); }
				else { stack1.push(rand() / 10); }
				VSQ[1]++;
				stack1.display();
			}
			if ((s2 == 2)&(VSQ[1] != 0))
			{
				stack1.pop();
				VSQ[1]--;
				stack1.display();
			}
			if ((s2 == 3)&(VSQ[1] != 0))
			{
				n = stack1.peek();
			}
			if ((s2 == 4)&(VSQ[1] != 0)) {
				m = stack1.count();
			}
			if ((s2 == 5)&(VSQ[1] != 0)) {
				stack1.reverse();
				stack1.display();
			}
			cout << "\nВыберите действие для 2 Стека:\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
			cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
			cout << "7.Выход\n";
			cin >> s2;
		}
		cout << "\n1Стек";
		stack.display();
		cout << "\n2Стек";
		stack1.display();
		cout << "\nРавны ли стркутуры:";
		if (stack == stack1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\nНеравны ли структуры";
		if (stack != stack1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Стек > 2 Стек: ";
		if (stack > stack1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Стек >= 2 Стек: ";
		if (stack >= stack1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Стек < 2 Стек: ";
		if (stack < stack1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Стек <= 2 Стек: ";
		if (stack <= stack1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Стек\n";
		stack.display();
		cout << "\n2 Стек\n";
		stack1.display();
		if (VSQ[0] == VSQ[1])
		{
			cout << "\nОбмен данными между структурами:";
			swap(stack, stack1);
			cout << "\n1 Стек";
			stack.display();
			cout << "\n2 Стек";
			stack1.display();
		}
		break;
	}

	case 3: {
		cout << "Выберите тип Очереди:\n1.int\n2.float\n";
		cin >> s1;
		if (s1 == 1)
		{
			Queue<int> queue(0);
		}
		cout << "\nВыберите действие для 1 Очередь :\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
		cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
		cout << "7.Выход\n";
		cin >> s2;
		while (s2 != 7)
		{
			if (s2 == 1) {
				if (s1 == 1) { queue.push(rand()); }
				else { queue.push(rand() / 10); }
				VSQ[0]++;
				queue.display();
			}
			if ((s2 == 2)&(VSQ[0] != 0))
			{
				queue.pop();
				VSQ[0]--;
				queue.display();
			}
			if ((s2 == 3)&(VSQ[0] != 0))
			{
				n = queue.peek();
			}
			if ((s2 == 4)&(VSQ[0] != 0))
			{
				m = queue.count();
			}
			if ((s2 == 5)&(VSQ[0] != 0))
			{
				queue.reverse();
				queue.display();
			}
			cout << "\nВыберите действие:\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
			cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
			cout << "7.Выход\n";
			cin >> s2;
		}

		cout << "\nВыберите действие для 2 Очередь:\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
		cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
		cout << "7.Выход\n";
		cin >> s2;
		while (s2 != 7)
		{
			if (s2 == 1)
			{
				if (s1 == 1) { queue1.push(rand()); }
				else { queue1.push(rand() / 10);
			}
				VSQ[1 ]++;
				queue1.display();
			}
			if ((s2 == 2)&(VSQ[0] != 0))
			{
				queue1.pop();
				VSQ[1]--;
				queue1.display();
			}
			if ((s2 == 3)&(VSQ[1] != 0))
			{
				n = queue1.peek();
			}
			if ((s2 == 4)&(VSQ[1] != 0))
			{
				m = queue1.count();
			}
			if ((s2 == 5)&(VSQ[1] != 0)) {
				queue1.reverse();
				queue1.display();
			}
			cout << "\nВыберите действие:\n1.Вставка элемента\n2.Удаление элемента\n3.Значение вершины\n";
			cout << "4.Количество элементов структуры\n5.Реверс структуры\n6.Произвольный доступ к элементу(только для вектора)\n";
			cout << "7.Выход\n";
			cin >> s2;
		}

		cout << "\n1Очередь";
		stack.display();
		cout << "\n2Очередь";
		stack1.display();
		cout << "\nРавны ли стркутуры:";
		if (queue == queue1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\nНеравны ли структуры";
		if (queue != queue1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Очередь > 2 Очередь: ";
		if (queue > queue1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Очередь >= 2 Очередь: ";
		if (queue >= queue1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Очередь < 2 Очередь: ";
		if (queue < queue1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Очередь <= 2 Очередь: ";
		if (queue <= queue1) { cout << "да\n"; }
		else { cout << "нет\n"; }
		cout << "\n1 Очередь\n";
		queue.display();
		cout << "\n2 Очередь\n";
		queue1.display();
		if (VSQ[0] == VSQ[1])
		{
			cout << "\nОбмен данными между структурами:";
			swap(queue, queue1);
			cout << "\n1 Вектор";
			queue.display();
			cout << "\n2 Вектор";
			queue1.display();
		}
		break;
	}
	}
	getchar();
	return 0;
}
