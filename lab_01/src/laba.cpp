# include <iostream>
#include"Vektor.h"
#include"Stack.h"
#include"Queue.h"
using namespace std;



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
				if (s1 == 1) { vektor1.push(rand()); }
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
		cout << "\nНеравны ли структуры:";
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
		cout << "\nНеравны ли структуры:";
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
				else {
					queue1.push(rand() / 10);
				}
				VSQ[1]++;
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
		cout << "\nНеравны ли структуры:";
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
