#include"pch.h"
#include<iostream>
#include"Vektor.h"
#include"Stack.h"
#include"Queue.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	Vektor <float> vektor(0), vektor1(0);
	Stack <float> stack(0), stack1(0);
	Queue <float> queue(0), queue1(0);
	vektor.push(11);
	vektor.push(12);
	vektor.push(13);
	vektor.push(14);
	vektor.display();
	cout << "\nRazmer1\n"<<vektor.count() << endl;
	vektor1.push(21);
	vektor1.push(22);
	vektor1.push(23);
	vektor1.display();
	cout << "\nRazmer2\n" << vektor1.count() << endl;

	swap(vektor, vektor1);
	vektor.display();
	cout << "\nRazmer1\n" << vektor.count() << endl;
	vektor1.display();
	cout << "\nRazmer2\n" << vektor1.count() << endl;
	getchar();
	return 0;
}
