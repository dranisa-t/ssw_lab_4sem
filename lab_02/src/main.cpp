#include <iostream>
#include "Simply_List.h"
#include "Doubly_List.h"
#include "Ring_Buffer.h"
using namespace std;

int main() {
   	Ring_Buffer<int> buffer1(5), buffer2(5), buffer(10);
	buffer1.push_back(0);
	buffer1.push_back(3);
	buffer1.push_back(5);
	buffer1.screen();

	buffer2.push_back(6);
	buffer2.push_back(8);
	buffer2.push_back(18);
	buffer2.screen();

    buffer.merger(buffer1, buffer2);
    buffer.screen();
    cout << "\t" << endl;
    return 0;
}

