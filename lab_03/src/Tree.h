
#ifndef gTree
#define gTree
//выдаёт ошибку "Tree<int>::Node *Tree<int>::pop_(Tree<int>::Node *)": невозможно преобразовать аргумент 1 из "T" в "Tree<int>::Node *"	labaratornay 3	c:\users\user\source\repos\labaratornay 3\labaratornay 3.cpp	159	
//я нет удаление узла и корня


#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Tree {
private:
    class Node {
    public:
        vector<Node*> pointTrees;
        T value{ 0 };
        explicit Node(T data)
        {
            value = data;
            pointTrees.clear();
        }
        ~Node() = default;
    };
    int Size{ 0 };
    Node* root{ nullptr };
    vector<T> elements_tree;
    vector<int> it;
    vector<Node*> Find;
    vector<int> Height_;


    void ListDel(Node* elm, Node* search) {
        for (int i = 0; i < elm->pointTrees.size(); i++) {
            if (elm->pointTrees.begin()[i] == search) {
                for (int i = 0; i < elements_tree.size(); i++)
                    if (search->value == elements_tree[i]) {
                        elements_tree.erase(elements_tree.begin() + i);
                        break;
                    }
                elm->pointTrees.erase(elm->pointTrees.begin() + i);
                Size--;
                break;
            }
            ListDel(elm->pointTrees.begin()[i], search);
        }
    }

    void NodeFind(Node* node, T d) 
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->value == d)
        {
            Find.push_back(node);
        }
        for (int i = 0; i < node->pointTrees.size(); i++)
            NodeFind(node->pointTrees.begin()[i], d);
    }

    int NodeHeight(Node* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int MHeight = 0;
        for (int i = 0; i < node->pointTrees.size(); i++) 
        {
            int height = NodeHeight(node->pointTrees.begin()[i]);
            if (height > MHeight)
            {
                MHeight = height;
            }
        }
        return MHeight + 1;
    }

    int NodePath(const Node* node, T d) 
    {
        int height = 0;
        for (int i = 0; i < node->pointTrees.size(); i++)
            height = NodePath(node->pointTrees.begin()[i], d);
        height++;
        if (node->value == d)
        {
            Height_.push_back(height + 1);
        }
        return height;
    }

    void display(Node* node) 
    {
        cout << "(" << node->value << ")";
        for (int i = 0; i < node->pointTrees.size(); i++)
            display(node->pointTrees.begin()[i]);
        if (node != root)
        {
            cout << ".";
        }
        if (node->pointTrees.size() == 0)
        {
            return;
        }
    }
    void NodeDelete(Node* elm)
    {
        if (elm != nullptr)
        {
            for (int i = 0; i < elm->pointTrees.size(); i++)
                NodeDelete(elm->pointTrees.begin()[i]);
            elm->pointTrees.clear();
            delete elm;
        }
    }
    void RootDel(Node* search)
    {
        Node* new_root = root->pointTrees.begin()[0];
        Node* old_root = root;
        for (int i = 1; i < old_root->pointTrees.size(); i++)
            new_root->pointTrees.push_back(old_root->pointTrees.begin()[i]);
        root = new_root;
        delete old_root;
        Size--;
    }

    void KnotDel(Node* node, Node* search) 
    {
        for (int i = 0; i < node->pointTrees.size(); i++) 
        {
            if (node->pointTrees.begin()[i] == search) 
            {
                Node* new_search = search->pointTrees.begin()[0];
                Node* old_search = search;
                for (int i = 1; i < old_search->pointTrees.size(); i++)
                    new_search->pointTrees.push_back(old_search->pointTrees.begin()[i]);
                node->pointTrees.erase(node->pointTrees.begin() + i);
                node->pointTrees.push_back(new_search);
                delete old_search;
                Size--;
                break;
            }
            KnotDel(node->pointTrees.begin()[i], search);
        }
    }

    void Del(Node* node, Node* search) 
    {

        if (search->pointTrees.size() == 0) 
        {
            ListDel(node, search);
            return;
        }
        else if (search == root)
        {
            RootDel(search);
            return;
        }
        else if (search->pointTrees.size() != 0)
        {
            KnotDel(node, search);
            return;
        }
    }

    bool Equally (Node* b1, Node* b2)
    {
        if (b1->pointTrees.size() != b2->pointTrees.size())
        {
            return false;
        }
        bool equally = true;
        equally = (b1->value == b2->value);
        if (equally)
            for (int i = 0; i < b1->pointTrees.size(); i++) 
            {
                equally = Equally(b1->pointTrees.begin()[i], b2->pointTrees.begin()[i]);
                if (!equally)
                {
                    return false;
                }
            }
        else
        {
            return false;
        }
        return equally;
    }

    bool more (Node* b1, Node* b2)
    {
        bool over = true;
        if (b1->val > b2->val)
        {
            return true;
        }
        else if (b1->val < b2->val)
        {
            return false;
        }
        over = (b1->val == b2->val);
        if (over)
            for (int i = 0; i < b1->pointTrees.size(); i++)
            {
                over = more(b1->pointTrees.begin()[i], b2->pointTrees.begin()[i]);
                if (!over) return false;
            }
        else return false;
        return over;
    }

public:
    Tree() = default;

    Tree(const std::initializer_list<T>& tree)
    {
        for (int i = 0; i < tree.size(); i++) 
        {
            push(root, tree.begin()[i]);
        }
    }

    ~Tree()
    {
        NodeDelete(root);
    }

    void push(Node* p, T data) 
    {
        elements_tree.push_back(data);
        if (root == nullptr) root = new Node(data);
        else p->pointTrees.push_back(new Node(data));
        Size++;
    }

    void pop(Node* node)
    {
        if (Size == 0) throw std::out_of_range("tree is empty");
        if (node->pointTrees.size() != 0) throw std::out_of_range("this element is not list");
        DeleteListok(root, node);
    }

    int count()
    {
        return Size;
    }

    int height()
    {
        if (Size == 0)
        {
            throw std::out_of_range("tree is empty");
        }
        if (Size == 1)
        {
            return 0;
        }
        return heightElement(root);
    }

    vector<Node*> find(T d) 
    {
        if (Size == 0)
        {
            throw std::out_of_range("tree is empty");
        }
        Find.clear();
        NodeFind(root, d);
        if (Find.empty())
        {
            throw std::out_of_range(" tree is haven't this element");
        }
        return Find;
    }

   
    vector<int> path(T d) 
    {
        if (Size == 0)
        {
            throw std::out_of_range("tree is empty");
        }
        Height_.clear();
        PathElement(root, d);
        if (Height_.size() == 0)
        {
            throw std::out_of_range("tree is haven't this element");
        }
        return Height_;
    }

    void print()
    {
        if (Size == 0)
        {
            throw std::out_of_range("tree is empty");
        }
        cout << endl;
        display(root);
        cout << endl;
    }

    void erase(Node* elm)
    {
        if (Size == 0)
        {
            throw std::out_of_range("tree is empty");
        }
        DeleteElement(root, elm);
        for (int i = 0; i < elements_tree.size(); i++)
            if (elm->value == elements_tree[i]) 
            {
                elements_tree.erase(elements_tree.begin() + i);
                break;
            }
    }


    bool operator > (Tree<T> const& m) 
    {
        if (this->Size == 0 || m.Size == 0)
        {
            throw std::out_of_range("tree is empty");
        }
        if (!Equally(this->root, m.root))
        {
            return more(this->root, m.root);
        }
        else return false;
    }

    bool operator < (Tree<T> const& m) 
    {
        return !(this->operator>=(m));
    };

    bool operator >= (Tree<T> const& m)
    {
        return (this->operator>(m) || this->operator==(m));
    };

    bool operator <= (Tree<T> const& m)
    {
        return !(this->operator>(m));
    };
    bool operator == (Tree<T> const& m)
    {
        if (this->Size == 0 || m.Size == 0)
        {
            throw std::out_of_range("tree is empty");
        }
        return Equally(this->root, m.root);
    }

    bool operator != (Tree<T> const& m)
    {
        return !(this->operator==(m));
    };
};
#endif //gTree