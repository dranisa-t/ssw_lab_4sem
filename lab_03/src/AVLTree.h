#ifndef AVL_Tree
#define AVL_Tree

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


template <class T>
class AVLTree
{
private:
	class AVLNode
	{
	public:
		int key_;
		int height_;

		AVLNode* left_node_;
		AVLNode* right_node_;


		AVLNode(int key, AVLNode* left_node = nullptr, AVLNode* right_node = nullptr)
		{
			key_ = key;
			left_node_ = left_node;
			right_node_ = right_node;
			height_ = 0;
		}
		~AVLNode() = default;
	};
	AVLNode* root_;
	int Size{ 0 };
	vector<int> vis;

	AVLNode* right_rotation(AVLNode* p)
	{
		AVLNode* new_p = p->left_node_;
		p->left_node_ = new_p->right_node_;
		new_p->right_node_ = p;

		p->height_ = max(sub_tree_height(p->left_node_), sub_tree_height(p->right_node_));
		new_p->height_ = max(sub_tree_height(new_p->left_node_), sub_tree_height(new_p->right_node_));

		return new_p;
	}

	AVLNode* left_rotation(AVLNode* p)
	{
		AVLNode* new_p = p->right_node_;
		p->right_node_ = new_p->left_node_;
		new_p->left_node_ = p;

		p->height_ = max(sub_tree_height(p->left_node_), sub_tree_height(p->right_node_));
		new_p->height_ = max(sub_tree_height(new_p->left_node_), sub_tree_height(new_p->right_node_));

		return new_p;
	}

	AVLNode* maximum_node_of_tree(AVLNode* node)
	{
		if (node->right_node_ == nullptr)
		{
			return node;
		}
		else
		{
			return maximum_node_of_tree(node->right_node_);
		}
	}

	int sub_tree_height(AVLNode* node)
	{
		return (node != nullptr) ? node->height_ + 1 : 0;
	}

	AVLNode* insert_(T key, AVLNode* node)
	{
		if (node == nullptr)
		{
			return node = new AVLNode(key);
		}

		if (key < node->key_)
		{
			node->left_node_ = insert_(key, node->left_node_);
		}
		else if (key > node->key_)
		{
			node->right_node_ = insert_(key, node->right_node_);
		}
		else if (node->key_ == key) return node;

		int height_L = sub_tree_height(node->left_node_);
		int height_R = sub_tree_height(node->right_node_);

		node->height_ = max(height_L, height_R);

		int balance_factor = height_L - height_R;

		if (balance_factor > 1)//L
		{
			if (key < node->left_node_->key_)//L
			{
				return node = right_rotation(node);
			}
			else//R
			{
				node->left_node_ = left_rotation(node->left_node_);
				return node = right_rotation(node);
			}
		}
		else if (balance_factor < -1)//R
		{
			if (key < node->right_node_->key_)//L
			{
				node->right_node_ = right_rotation(node->right_node_);
				return node = left_rotation(node);
			}
			else//R
			{
				return node = left_rotation(node);
			}
		}
		Size++;
		return node;
	}

	AVLNode* pop_(int key, AVLNode* node)
	{
		if (node == nullptr) return nullptr;

		if (key < node->key_)
		{
			node->left_node_ = pop_(key, node->left_node_);
		}
		else if (key > node->key_)
		{
			node->right_node_ = pop_(key, node->right_node_);
		}
		else 
		{
			if (node->left_node_ == nullptr && node->right_node_ == nullptr)
			{
				delete node;
				return nullptr;
			}
			else if (node->left_node_ == nullptr && node->right_node_ != nullptr)
			{
				AVLNode* sub_right_tree = node->right_node_;
				delete node;
				return sub_right_tree;
			}
			else if (node->left_node_ != nullptr && node->right_node_ == nullptr)
			{
				AVLNode* sub_left_tree = node->left_node_;
				delete node;
				return sub_left_tree;
			}
			else
			{
				AVLNode* maxium_node_in_sub_left_tree = maximum_node_of_tree(node->left_node_);
				node->key_ = maxium_node_in_sub_left_tree->key_;
				node->left_node_ = pop_(maxium_node_in_sub_left_tree->key_, node->left_node_);
			}
		}

		int height_L = sub_tree_height(node->left_node_);
		int height_R = sub_tree_height(node->right_node_);

		node->height_ = max(height_L, height_R);

		int balance_factor = height_L - height_R;

		if (balance_factor > 1)//L
		{
			if (sub_tree_height(node->left_node_->left_node_) > sub_tree_height(node->left_node_->right_node_))//L
			{
				return node = right_rotation(node);
			}
			else//R
			{
				node->left_node_ = left_rotation(node->left_node_);
				return node = right_rotation(node);
			}
		}
		else if (balance_factor < -1)//R
		{
			if (sub_tree_height(node->right_node_->left_node_) > sub_tree_height(node->right_node_->right_node_))//L
			{
				node->right_node_ = right_rotation(node->right_node_);
				return node = left_rotation(node);
			}
			else//R
			{
				return node = left_rotation(node);
			}
		}
		Size--;
		return node;
	}
	void deleteElement(AVLNode* m) {
		if (m != nullptr) {
			deleteElement(m->left_node_);
			deleteElement(m->right_node_);
			delete m;
			m = nullptr;
		}
		else return;
	}

	void print(AVLNode* node)
	{
		if (node == NULL) {
			cout << ".";
			return;
		}
		cout << "(" << node->key_ << ")";
		print(node->left_node_);
		print(node->right_node_);
	}


public:
	int count()
	{
		return Size;
	}

	vector<int> path(int d)
	{
		if (Size == 0)
		{
			throw std::out_of_range("tree is empty");
		}
		vis.clear();
		int i = 0;
		AVLNode* element = root_;
		while (element != nullptr)
		{
			if (d < element->key_)
			{
				element = element->left_node_;
			}
			else if (d > element->key_)
			{
				element = element->right_node_;
			}
			else 
			{
				vis.push_back(i);
				element = element->right_node_;
			}
			i++;
		}
		if (vis.empty())
			throw std::out_of_range("Tree is haven't this element");
		return vis;
	}
	AVLTree()
	{
		root_ = nullptr;
	}

	~AVLTree()
	{
		deleteElement(root_);
	}

	void insert(int key)
	{
		root_ = insert_(key, root_);
	}

	void pop(int key)
	{
		root_ = pop_(key, root_);
	}
	AVLNode* Find(int key_)
	{
		AVLNode* key = root_;
		while (key != nullptr)
		{
			if (key->key_ == key_)
			{
				return key;
			}
			if (key->key_ > key_)
			{
				key = key->left_node_;
			}
			else
			{
				key = key->right_node_;
			}
		}
	}
	void display()
	{
		print(root_);
		cout << endl;
	}

	bool operator == (AVLNode const& p)
	{
		if (this->Size == 0) 
			throw out_of_range("Tree is empty");
		if (this->Size > 0) 
			throw out_of_range("Tree is empty");
		return ravno(this->root_, this->root_);
	}

	bool ravno(AVLNode* d1, AVLNode* d2)
	{
		if (d1 == nullptr && d2 == nullptr) return true;
		if (d1 == nullptr || d2 == nullptr) return false;
		bool ravn = true;
		ravn = (d1->key_ == d2->key_);
		if (ravn)
		{
			ravn = ravno(d1->left_node_, d2->left_node_);
			ravn = ravno(d1->right_node_, d2->right_node_);
		}
		if (!ravn) return false;
		return ravn;
	}

	bool operator !=(AVLNode const& p)
	{
		return !(this->operator==(p));
	}

	bool operator > (AVLNode const& p)
	{
		if (this->Size == 0 || this->Size == 0)throw std::out_of_range("tree is empty");
		return comp(this->root_, this->root_);
	}
	bool comp(AVLNode* d1, AVLNode* d2)
	{
		if (d1 != nullptr && d2 == nullptr)
		{
			return true;
		}
		if (d1 == nullptr && d2 != nullptr)
		{
			return false;
		}
		if (d1 == nullptr && d2 == nullptr)
		{
			return false;
		}
		bool com = true;
		if (d1->key_ > d2->key_)
		{
			return true;
		}
		if (d1->key_ < d2->key_)
		{
			return false;
		}
		com = (d1->key_ == d2->key_);
		if (com)
		{
			com = comp(d1->left_node_, d2->left_node_);
		}
		else
		{
			return false;
		}
		if (com)
		{
			com = comp(d1->right_node_, d2->right_node_);
		}
		else
		{
			return false;
		}
		return com;

	}
	bool operator >=(AVLNode const& p)
	{
		return !(this->operator>(p) || this->operator ==(p));
	}
	bool operator<(AVLNode const& p)
	{
		return !(this->operator>=(p));
	}
	bool operator <=(AVLNode const& p)
	{
		return!(this->operator>(p));
	}

};
#endif //AVL_Tree