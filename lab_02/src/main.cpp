#include <iostream>
#include "Simply_List.h"
#include "Doubly_List.h"
#include "Ring_Buffer.h"
using namespace std;

int main() {

    Ring_Buffer<int> buffer1(4), buffer2(4), buffer(8);
    buffer1.push_back(0);
    buffer1.push_back(1);
    buffer1.push_back(2);
    buffer1.screen();

    buffer2.push_back(6);
    buffer2.push_back(5);
    buffer2.push_back(30);
    buffer2.screen();

    buffer.merger(buffer1, buffer2);
    buffer.screen();
    return 0;

}
