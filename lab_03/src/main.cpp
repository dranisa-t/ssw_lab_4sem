#include <iostream>
#include "AVLTree.h"
#include "Tree.h"
using namespace std;




int main()
{

	Tree<int> trees{ 10,20,30,5 };
	auto a = trees.find(5);
	trees.print();
	trees.push(a.at(2), 7);
	trees.print();
	AVLTree<int> avltree1, avltree2;
	avltree1.insert(5);
	avltree1.insert(1);
	avltree1.insert(7);
	avltree1.insert(3);
	avltree2.insert(4);
	avltree2.insert(8);
	avltree2.insert(6);
	avltree2.insert(9);
	avltree1.pop(8);
	avltree1.display();
	avltree2.display();
	return 0;
}
