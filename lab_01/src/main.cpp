#include <iostream>
#include"Vektor.h"
#include"Stack.h"
#include"Queue.h"
#include <vector>
#include <stack>
#include <queue>
#include <chrono>
using ms = std::chrono::milliseconds;
using namespace std;

int main(int charc, char** argv)
{
    Vektor <int> vektor, vektor1;
    vector<int> v;
    Stack <int> steck, steck1;
    stack <int> s;
    Queue <int> otshered, otshered1;
    queue <int> q;

    vektor.push(11);
    vektor.push(12);
    vektor.push(13);
    vektor.push(14);
    vektor.push(15);
    vektor1.push(21);
    vektor1.push(22);
    vektor1.push(23);
    vektor1.push(24);
    vektor1.push(25);
    vektor1.push(26);

    cout << "\n1 vektor\n";
    vektor.display();
    cout << "\n2 vektor\n";
    vektor1.display();
    swap(vektor, vektor1);
    cout << "\n1 vektor\n";
    vektor.display();
    cout << "\n2 vektor\n";
    vektor1.display();

    steck.push(30);
    steck.push(31);
    steck.push(32);
    steck.push(33);
    steck.push(34);
    steck1.push(40);
    steck1.push(50);
    steck1.push(41);
    steck1.push(10);
    steck1.push(48);
    steck1.push(49);

    cout << "\n1 stack\n";
    steck.display();
    cout << "\n2 stack\n";
    steck1.display();
    swap(steck, steck1);
    cout << "\n1 stack\n";
    steck.display();
    cout << "\n2 stack\n";
    steck1.display();

    otshered.push(18);
    otshered.push(19);
    otshered.push(20);
    otshered.push(24);
    otshered.push(25);
    otshered.push(26);
    otshered1.push(17);
    otshered1.push(16);
    otshered1.push(15);
    otshered1.push(14);
    otshered.push(13);

    cout << "\n1 queue\n";
    otshered.display();
    cout << "\n2 queue\n";
    otshered1.display();
    swap(otshered, otshered1);
    cout << "\n1 queue\n";
    otshered.display();
    cout << "\n2 queue\n";
    otshered1.display();

    cout << "\nSravnenie vektor\nVstavka element\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)
        vektor.push(11);
    auto end = std::chrono::high_resolution_clock::now();
    auto res_time = std::chrono::duration_cast<ms>(end - start).count();
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)
        v.push_back(11);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout << "Vektor=" << res_time << endl;
    cout << "std vector=" << res_time1 << endl;

    cout << "Kolitchestvo elements\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        vektor.count();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        v.size();
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout << "Vektor=" << res_time << endl;
    cout << "std vector=" << res_time1 << endl;

    cout << "\nSravnenie stack\nVstavka element\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)
        steck.push(11);
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)
        s.push(11);
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout << "Stack=" << res_time << endl;
    cout << "std stack=" << res_time1 << endl;

    cout << "Vershina stack\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        steck.peek();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        s.top();
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout << "Stack=" << res_time << endl;
    cout << "std stack=" << res_time1 << endl;

    cout << "\nSravnenie otchered\nVstavka element\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)
        otshered.push(11);
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)
        q.push(11);
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout << "Queue=" << res_time << endl;
    cout << "std queue=" << res_time1 << endl;

    cout << "Vershina otchered\n";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        otshered.peek();
    end = std::chrono::high_resolution_clock::now();
    res_time = std::chrono::duration_cast<ms>(end - start).count();
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
        q.front();
    end1 = std::chrono::high_resolution_clock::now();
    res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
    cout << "Queue=" << res_time << endl;
    cout << "std queue=" << res_time1 << endl;
    getchar();
    return 0;
}